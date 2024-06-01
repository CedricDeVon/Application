
using namespace std;

class User_File_Api
{
public:
    static void create_one_user(string email, string password, string first_name, string last_name, int age)
    {
        User_File_Data user_file_data(email, password, first_name, last_name, age);

        user_file_proxy.open_to_append();
        user_file_proxy.append_line(user_file_data.get_values());
        user_file_proxy.close();
    }

    static string read_one_user(string email)
    {

    }

    static void update_one_user()
    {

    }

    static void delete_one_user()
    {

    }

    static void delete_all_users()
    {

    }
};

/*
Requirements:
- Schema: |key|value| |value
- Required Implementation
- NULL Implementation

- Operations
    - Create
        - 1 /

    - Update
        - 1
        - n
    - Delete
        - 1 *
        - n *
    - Copy
        - 1
        - n
    - Retrieve
        - 1
        - n
*/
