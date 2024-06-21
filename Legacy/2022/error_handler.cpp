using namespace std;

class Error_Handler
{
public:
    static void throw_error(string message)
    {
        cout << "Error";
        cout << ": ";
        cout << message;

        exit(-1);
    }
};