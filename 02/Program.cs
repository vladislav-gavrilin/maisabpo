using CRCcs;
using System;
using ConsoleTables;

namespace rscs
{
    class Program
    {
        static int Main(string[] args)
        {
            Fun();
            return 0;
        }

        static unsafe void Fun()
        {
            int amount_of_bits = 32;
            uint crc_32_new;
            uint crc_16_new;
            //------------------------------------------------------//
            //массивы для подсчета количества ошибок
            int[] crc16_cnt = new int[amount_of_bits];
            int[] crc32_cnt = new int[amount_of_bits];
            int[] xor_cnt = new int[amount_of_bits];
            int[] N = new int[amount_of_bits];

            for (int i = 0; i < amount_of_bits; i++)
            {
                crc16_cnt[i] = 0;
                crc32_cnt[i] = 0;
                xor_cnt[i] = 0;
                N[i] = 0;
            }
            //------------------------------------------------------//

            int a;
            int USER_DATA_SIZE = 256; //размер массива данных

            byte[] user_data = new byte[USER_DATA_SIZE];

            // инициализация пользовательских данных
            Console.WriteLine("инициализация пользовательских данных");
            for (a = 0; a < USER_DATA_SIZE; a++)
                user_data[a] = (byte)a;

            printData(user_data);

            fixed (byte* i8_ptr = user_data)
            {
                long t0, t1;
                uint* i32_ptr = (uint*)i8_ptr;
                uint v0 = i32_ptr[0];

                uint crc_32 = CRC.crc32b(user_data);
                uint crc_16 = CRC.Crc16Ccitt(user_data);
                int xor = 0;
                foreach (int value in user_data)
                {
                    xor ^= value;
                }
                t0 = Environment.TickCount;
                    for (uint x = 1; x <= 0xFFFFFF; x++)
                    {
                        uint count = BitCount(x); //считаем, сколько единичек в числе
                        i32_ptr[0] = v0 ^ (uint)x; //портим

                        crc_32_new = CRC.crc32b(user_data);
                        crc_16_new = CRC.Crc16Ccitt(user_data);

                        int xor_new = 0;
                        foreach (int value in user_data)
                        {
                            xor_new ^= value;
                        }

                        if (xor_new == xor)
                            xor_cnt[count]++;
                        if (crc_16_new == crc_16)
                            crc16_cnt[count]++;
                        if (crc_32_new == crc_32)
                            crc32_cnt[count]++;
                        N[count]++;
                    
                        if(x % 1000 == 0)
                        {
                            t1 = Environment.TickCount;
                            if(t1 - t0 > 1000)
                            {
                                Console.Write($"\r{(x * 100.0) / 0xFFFFFF:0.#}%");
                                t0 = t1;
                            }          
                        }
                    }

                var table = new ConsoleTable("n_bit", "N", "xor", "crc16", "crc32");
                for (uint i = 1; i < amount_of_bits; i++)
                {
                    table.AddRow(i, N[i], xor_cnt[i], crc16_cnt[i], crc32_cnt[i]);
                }
                table.Write();
                Console.WriteLine();
            }
        }

        private static uint BitCount(uint number)
        {
            uint count = 0;

            while (number != 0)
            {
                count += number & 1;
                number >>= 1;
            }

            return count;
        }

        static void printData(byte[] data)
        {
            int c = 0;
            for (int n = 0; n < data.Length; ++n, ++c)
            {
                if (c == 32)
                {
                    Console.WriteLine();
                    c = 0;
                }
                Console.Write($"{data[n]:X02} ");
            }
            Console.WriteLine();
        }
    }
}