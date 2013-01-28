
import java.io.*;
import java.util.Collection;
import java.util.StringTokenizer;

public class Solution
{
    public static void main(String[] args) throws IOException
    {
        Reader reader = new Reader("in");
        Writer writer = new Writer(System.out, false);

        int[] array = new int[100];
//        array[0] = 0;
        array[1] = 1;
//        array[2] = 0;
        array[3] = 1;
        array[4] = 1;
        for (int i = 5; i < 100; ++i)
        {
            if (array[i - 1] * array[i - 3] * array[i - 4] == 0)
            {
                array[i] = 1;
            }
        }
        writer.print(array);

        reader.close();
        writer.finish();
    }


    public static class Reader extends BufferedReader
    {
        private StringTokenizer tokenizer;

        public Reader(String fileName) throws FileNotFoundException
        {
            super(new FileReader(fileName));
        }

        public Reader(InputStream in)
        {
            super(new InputStreamReader(in));
        }

        int[] readIntArray(int size) throws IOException
        {
            int[] array = new int[size];
            for (int i = 0; i < size; ++i)
            {
                array[i] = nextInt();
            }
            return array;
        }

        int nextInt() throws IOException
        {
            return Integer.parseInt(nextString());
        }

        long nextLong() throws IOException
        {
            return Long.parseLong(nextString());
        }

        double nextDouble() throws IOException
        {
            return Double.parseDouble(nextString());
        }

        String nextString() throws IOException
        {
            while (tokenizer == null || !tokenizer.hasMoreTokens())
            {
                tokenizer = new StringTokenizer(readLine());
            }
            return tokenizer.nextToken();
        }

        public String nextLine() throws IOException
        {
            return readLine();
        }
    }


    public static class Writer extends PrintWriter
    {
        private boolean fromFile;
        private long start;


        public Writer(OutputStream outputStream, boolean fromFile)
        {
            super(new BufferedOutputStream(outputStream));
            this.fromFile = fromFile;
            start = System.nanoTime();
        }

        public void finish()
        {
            if (fromFile)
            {
                println("time: " + (System.nanoTime() - start) / 1000000);
            }
            flush();
            close();
        }

        public void print(int[] array)
        {
            for (int i = 0; i < array.length; i++)
            {
                if (i != 0)
                    print(' ');
                print(array[i]);
            }
        }

        public <T> void print(Collection<T> collection)
        {
            boolean first = true;
            for (T e : collection)
            {
                if (!first)
                {
                    print(' ');
                }
                print(e);
                first = false;
            }
        }
    }
}

