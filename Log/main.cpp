#include "log.h"

int main()
{
    try
    {
        // log object
        Log current_log;

        // work until shutdown
        while (true)
        {
            // checking for error for write into the file
            if (!current_log.MakeLog())
            {
                cout << "Writing into the file: write_error\n";
                return write_error;
            }
            Sleep(t10);
        }
    }
    catch (const exception& Error)
    {
        cout << "Program can't work correct.\n";
    }
}
