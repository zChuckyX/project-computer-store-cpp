#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <cstring>

using namespace std;

class Desktop {
    public:
        void desktop(string data_1, string data_2, int count, int choice, const string username, const int pos);
        void Change (string data_1, string data_2, const string username, const int pos, int count);
        void case_list(string data_1, string data_2, int count, int choice, const string username, const int pos, string choose);
        void case2_list(string data_1, string data_2, int count, int choice, const string username, const int pos, string choose, string word);
        void case3_list(string data_1, string data_2, int count, int choice, const string username, const int pos, string choose, string word, string data_3);
};

class Account : public Desktop {
    public:
        Account(string data_1, string data_2, int count) {
            cout << "---------------------------------------\n";
            cout << "         Welcome To Register\n";

            while (true) {
                cout << "Username (0 To Exit.) : "; cin >> data_1;

                if (data_1 == "0") {
                    break;
                }
                
                ifstream Username("user/username.txt");
                while (Username >> data_2) {
                    if (data_1 == data_2) {
                        break;
                    }
                }

                if (data_1 != data_2) {
                    break;
                } else {
                    cout << "This username is already registered." << endl;
                }
            }

            if (data_1 != "0") {
                while (true) {
                    cout << "Password (6 Numbers.) : "; cin >> data_2;

                    if (data_2.length() == 6) {
                        ofstream Username("user/username.txt", ios::in | ios::out | ios::app);
                        Username << data_1 << endl;
                        Username.close();
                        ofstream Password("user/password.txt", ios::in | ios::out | ios::app);
                        Password << data_2 << endl;
                        Password.close();
                        ofstream Cart("user/cart.txt", ios::in | ios::out | ios::app);
                        Cart << "0" << endl;
                        Cart.close();

                        ofstream Cart_junk("junk/user/cart/cart.txt", ios::in | ios::out | ios::app);
                        Cart_junk << "0" << endl;
                        Cart_junk.close();

                        data_2 = "user/cart/" + data_1 + ".txt";
                        fstream file_1;
                        file_1.open(data_2, ios::in | ios::out | ios::app);
                        file_1.close();

                        data_2 = "junk/user/stock/" + data_1 + ".txt";
                        fstream file_2;
                        file_2.open(data_2, ios::in | ios::out | ios::app);
                        file_2.close();

                        ifstream file_in("user/username.txt");
                        count = 0;
                        while (file_in >> data_1) {
                            count++;
                        }

                        ofstream Member_ID("user/member_id.txt", ios::in | ios::out | ios::app);

                        if (count >= 0 && count <= 9) {
                            data_2 = "00" + to_string(count);
                        } else if (count >= 10 && count <= 99) {
                            data_2 = "0" + to_string(count);
                        } else {
                            data_2 = count;
                        }

                        Member_ID << data_2 << endl;
                        Member_ID.close();  
                        break;
                    } 
                }

                cout << "---------------------------------------" << endl;
                cout << "            Register Success \n Member ID : "<< data_2 << "\n Username : " << data_1 << endl;
                cout << "---------------------------------------\n" << endl;
            } else {
                Desktop::desktop(data_1, data_2, count, 0, " ", 0);
            }
        }

        Account(string data_1, string data_2, int count, const string user) {
            cout << "---------------------------------------\n";
            cout << "        Welcome To Login\n";

            while (true) {
                count = 0;
                cout << "Username (0 To Exit.): "; cin >> data_1;
                
                if (data_1 == "0") {
                    break;
                }

                ifstream Username("user/username.txt");
                Username.seekg(0,ios::beg);

                while (Username >> data_2) {
                    count++;
                    if (data_1 == data_2) {
                        break;
                    }
                }

                if (data_1 == data_2) {
                    break;
                } else {
                    cout << data_1 << " Not Found." << endl;
                }
            }

            if (data_1 != "0") {
                const string username = data_1;
                const int pos = count;

                while (true) {
                    cout << "Password : "; cin >> data_2;

                    ifstream Password("user/password.txt");
                    Password.seekg(0,ios::beg);
                    for (int i = 0 ; i < pos ; i++) {
                        Password >> data_1;
                    }

                    if (data_2 == data_1) {
                        break;
                    } else {
                        cout << "The password is incorrect." << endl;
                    }
                }

                cout << "---------------------------------------" << endl;
                cout << "            Login Success" << endl;
                cout << "---------------------------------------\n" << endl;
                Desktop::desktop(data_1, data_2, count, 0, username, pos);
            } else {
                Desktop::desktop(data_1, data_2, count, 0, " ", 0);
            }
        }
};

class User : public Desktop {
    public:
        void confirm_username(string data_1, string data_2, const string username, const int pos, int count);
        void confirm_password(string data_1, string data_2, const int pos, int count, const string username);

        User(string data_1, string data_2, const string username, const int pos, int count) {
            cout << "---------------------------------------" << endl;
            cout << "           Change Username" << endl;
            cout << "Username : " << username << endl;

            while (true) {
                cout << "New Username (0 To Exit.) : "; cin >> data_1;

                ifstream user("user/username.txt");
                user.seekg(0, ios::beg);

                while (user >> data_2) {
                    if (data_2 == data_1) {
                        break;
                    }
                }

                if (data_2 == data_1) {
                    cout << "This name is already in use." << endl;
                } else {
                    break;
                }
            }

            if (data_1 == "0") {
                Desktop::desktop(data_1, data_2, 0, 0, username, pos);
            } else {
                confirm_username(data_1, data_2, username, pos, count);
            }         
        }

        User(string data_1, string data_2, const int pos, int count, const string username) {
            cout << "---------------------------------------" << endl;
            cout << "           Change Password" << endl;
            ifstream password("user/password.txt");

            for (int i = 0 ; i < pos ; i++) {
                password >> data_2;
            }

            cout << "Password : " << data_2 << endl;

            while (true) {
                cout << "New Password (0 To Exit.) : "; cin >> data_1;

                if (data_1.length() == 6) {
                    if (data_2 == data_1) {
                        cout << "This code is current." << endl;
                    } else {
                        break;
                    }
                } else if (data_1 == "0"){
                    break; 
                } else {
                    cout << "6 Numbers" << endl;
                }
            }

            if (data_1 == "0") {
                Desktop::desktop(data_1, data_2, 0, 0, username, pos);
            } else {
                confirm_password(data_1, data_2, pos, count, username);
            }         
        }
};

class Cart : public Desktop {
    public:
        void show_cart(string data_1, string data_2, int count, int choice, const string username, const int pos);
        void remove(string data_1, string data_2, int count, int choice, const string username, const int pos);
        void restock(string data_1, string data_2, int count, int choice, const string username, const int pos);
        void recart(string data_1, string data_2, int count, int choice, const string username, const int pos);
};

class Stock : public Desktop {
    public:
        void show_stock(string data_1, string data_2, int count, int choice, const string username, const int pos);
};

void conti(string data_1, string data_2, int count, int choice, const string username, const int pos);

int main() {
    Desktop dt;

    int count = 0 , choice = 0;
    string data_1 = " ", data_2 = " ";

    dt.desktop(data_1, data_2, count, choice, " ", 0);

    return 0;
}

void Register (string data_1, string data_2, int count) {
    Account account(data_1, data_2, count);
}

void Login (string data_1, string data_2, int count, const string username) {
    Account account(data_1, data_2, count, username);
}

void Desktop::Change (string data_1, string data_2, const string username, const int pos, int count) {
    cout << "---------------------------------------" << endl;
    cout << "           Changes System" << endl;
    cout << "1.Change Password     2.Change Username" << endl;
    cout << "---------------------------------------" << endl;

    while (true) {
        cout << "Enter Here (0 To Exit.) : "; cin >> data_1;

        if (data_1 == "0" || data_1 == "1" || data_1 == "2") {
            break;
        } else {
            cout << "0 - 2 Only." << endl;
        }
    }

    if (data_1 == "0") {
        Desktop::desktop(data_1, data_2, count, 0, username, pos);
    } else if (data_1 == "1") {
        User user(data_1, data_2, pos, count, username);
    } else if (data_1 == "2") {
        User user(data_1, data_2, username, pos, count);
    } 
}

void Desktop::desktop(string data_1, string data_2, int count, int choice, const string username, const int pos) {
    cout << "---------------------------------------\n";
    cout << "      Welcome To Comsci Have CPU\n";
    if (username != " ") {
        cout << " Welcome " << username << endl;
        ifstream Cart("user/cart.txt");
        Cart.seekg(0, ios::beg);
        for (int i = 0 ; i < pos ; i++) {
            Cart >> data_1;
        }
        cout << " Cart " << data_1 << endl;
        Cart.close();
        data_1 = "9.Account";
    } else {
        data_1 = "9.Register";
    }

    cout << "   1.CPU                7.Cart\n   2.Mainboard          8.Login\n   3.GPU                " << data_1 << "\n   4.Ram \n   5.SSD \n   6.Power Supply\n";
    cout << "---------------------------------------\n";

    while (true) {
        cout << "Enter Here (0 To Stop.) : "; cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please Enter a Number!." << endl;
        } else if (choice >= 0 && choice <= 9) {
            break;  
        } else {
            cout << "Please Enter a Number between 0 and 9." << endl;
        }
    }
    
    conti(data_1, data_2, count, choice ,username, pos);
}

void Cart::show_cart(string data_1, string data_2, int count, int choice, const string username, const int pos) {
    if (username != " ") {
        int Total = 0;
        int n = 1;
        data_1 = "user/cart/" + username + ".txt";   
        ifstream Cart(data_1);
        cout << "---------------------------------------" << endl;
        cout << "         " << username <<" Cart List" << endl;

        while (getline(Cart,data_1)) {  
            ifstream stock("stock/stock_id.txt");
            stock.seekg(0, ios::beg);
            count = 0;
            while (stock >> data_2) {
                count++;
                if (data_1 == data_2) {
                    break;
                }
            }

            cout << n++ << ". Stock ID : " << data_1;
            ifstream stock_l("stock/stock_list.txt");
            stock_l.seekg(0, ios::beg);

            for (int i = 0 ; i < count ; i++) {
                getline(stock_l,data_1);
            }

            cout << "\n     Name : " << data_1;
            ifstream stock_v("stock/stock_value.txt");
            stock_v.seekg(0, ios::beg);

            for (int i = 0 ; i < count ; i++) {
                stock_v >> choice;
            }

            cout << "\n     Price : " << choice << " Baht" << endl;
            Total += choice;
        }

        if (n != 1) {
            cout << "\n1.Delete                Total : "<< Total << endl;
            cout << "---------------------------------------" << endl;

            while (true) {
                cout << "Enter Here (0 To Exit.): "; cin >> choice;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Please Enter a Number!." << endl;
                } else if (choice >= 0 && choice <= 1) {
                    break;  
                } else {
                    cout << "Please Enter a Number between 0 and 1." << endl;
                }
            }

            switch (choice) {
                case 0 :    
                    Desktop::desktop(data_1, data_2, count, choice ,username, pos);
                    break;
                case 1 :        
                    Cart::remove(data_1, data_2, count, choice ,username, pos);
                    break;
            }
        } else {
            Desktop::desktop(data_1, data_2, count, choice ,username, pos);
        }
    } else {
        Desktop::desktop(data_1, data_2, count, choice ,username, pos);
    }

}

void Cart::remove(string data_1, string data_2, int count, int choice, const string username, const int pos) {
    cout << "---------------------------------------" << endl;
    cout << "               Remove Items " << endl;

    while (true) {
        data_2 = "user/cart/" + username + ".txt";
        cout << "Enter Here (Stock ID) (0 To Exit.) : ";cin >> data_1;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please Enter a Number!." << endl;
        } else if (data_1 == "0") {
            break;
        } else {
            ifstream stock(data_2);
            stock.seekg(0, ios::beg); 

            while (stock >> data_2) {
                if (data_1 == data_2) {
                    break;
                }
            }

            if (data_1 == data_2) {
                break;
            }
        }
    }

    if (username != " " && data_1 == data_2) {
        restock(data_1, data_2, count, choice, username, pos);
        cout << "---------------------------------------" << endl;
        cout << "           Remove Stock Success" << endl;
        cout << "Stock ID : " << data_1 << endl;
        cout << "---------------------------------------" << endl;
        recart(data_1, data_2, count, choice, username, pos);
        Desktop::desktop(data_1, data_2, count, choice, username, pos);
    } else {
        Desktop::desktop(data_1, data_2, count, choice, username, pos);
    }
}

void Cart::restock(string data_1, string data_2, int count, int choice, const string username, const int pos) {
    string stock = data_1;
    data_1 = "junk/user/stock/" + username + ".txt";
    ofstream junk_secondary(data_1, ios::trunc);
    junk_secondary.close();

    ofstream secondary(data_1);
    data_1 = "user/cart/" + username +".txt";
    ifstream main(data_1);
    main.seekg(0,ios::beg);

    while (main >> data_2) {
        if (data_2 != stock) {
            secondary << data_2 << endl;
        }
    }

    data_1 = "user/cart/" + username +".txt";
    ofstream junk_main(data_1,ios::trunc);
    ofstream main_file(data_1);
    junk_main.close();

    data_1 = "junk/user/stock/" + username + ".txt";
    ifstream secondary_file(data_1);
    secondary_file.seekg(0,ios::beg);

    while (secondary_file >> data_2) {
        main_file << data_2 << endl;
    }    
}

void Cart::recart(string data_1, string data_2, int count, int choice, const string username, const int pos) {
    ofstream junk_cart("junk/user/cart/cart.txt", ios::trunc);

    ofstream cart_secondary("junk/user/cart/cart.txt");
    ifstream cart_main("user/cart.txt");
    cart_main.seekg(0, ios::beg);
    count = 0;

    while (cart_main >> choice) {
        count++;
        if (count == pos) {
            cart_secondary << choice - 1 << endl;
        } else {
            cart_secondary << choice << endl;
        }
    }

    ofstream cart("user/cart.txt", ios::trunc);

    ifstream cart_secon("junk/user/cart/cart.txt");
    ofstream cart_m("user/cart.txt");

    cart_secon.seekg(0, ios::beg);
    while (cart_secon >> data_1) {
        cart_m << data_1 << endl;
    }
}

void User::confirm_username(string data_1, string data_2, const string username, const int pos, int count) {
    while(true) {
        cout << "You Want To Change " << username << " To " << data_1 << " ? \nComfirm Y/N : "; cin >> data_2;

        if (data_2 == "Y" || data_2 == "N"){
            break;
        } else {
            cout << "Y or N Only." << endl;
        }
    }

    if (data_2 == "Y") {
        ofstream junk_second("junk/user/username.txt", ios::trunc);

        ifstream user_main("user/username.txt");
        ofstream user_second("junk/user/username.txt");
        user_main.seekg(0, ios::beg);
        count = 0;

        while (user_main >> data_2) {
            count++;
            if (count == pos) {
                user_second << data_1 << endl;
            } else {
                user_second << data_2 << endl;
            }
        }

        ofstream junk_main("user/username.txt", ios::trunc);

        ofstream user_m("user/username.txt");
        ifstream user_s("junk/user/username.txt");

        while (user_s >> data_2) {
            user_m << data_2 << endl;
        }

        cout << "---------------------------------------" << endl;
        cout << "       Change Username Completed" << endl;
        cout << "New Username : " << data_1 << endl;
        const string username = data_1;
        Desktop::desktop(data_1, data_2, count, 0, username, pos);
    } else if (data_2 == "N") {
        User(data_1, data_2, username, pos, count);
    }
}

void User::confirm_password(string data_1, string data_2, const int pos, int count, const string username){
    while(true) {
        cout << "You Want To Change " << data_2 << " To " << data_1 << " ? \nComfirm Y/N : "; cin >> data_2;

        if (data_2 == "Y" || data_2 == "N"){
            break;
        } else {
            cout << "Y or N Only." << endl;
        }
    }

    if (data_2 == "Y") {
        ofstream junk_second("junk/user/password.txt", ios::trunc);

        ifstream user_main("user/password.txt");
        ofstream user_second("junk/user/password.txt");
        user_main.seekg(0, ios::beg);
        count = 0;

        while (user_main >> data_2) {
            count++;
            if (count == pos) {
                user_second << data_1 << endl;
            } else {
                user_second << data_2 << endl;
            }
        }

        ofstream junk_main("user/password.txt", ios::trunc);

        ofstream user_m("user/password.txt");
        ifstream user_s("junk/user/password.txt");

        while (user_s >> data_2) {
            user_m << data_2 << endl;
        }

        cout << "---------------------------------------" << endl;
        cout << "       Change Password Completed" << endl;
        cout << "New Password : " << data_1 << endl;
        Desktop::desktop(data_1, data_2, count, 0, username, pos);
    } else if (data_2 == "N") {
        User(data_1, data_2, pos, count, username);
    }
}

void Stock::show_stock(string data_1, string data_2, int count, int choice, const string username, const int pos) {
    ifstream stock("stock/stock_id.txt");
    stock.seekg(0, ios::beg);
    Cart cart;
    count = 0;
    int n = 0;
    char stock_id[50][8];
    string determinants = data_2;
    
    cout << "---------------------------------------" << endl;
    cout << "               Stock List" << endl;

    if (choice == 1) {
        while (stock >> data_1) {
            count++;
            if (data_1[0] == determinants[0]) {
                strcpy(stock_id[n], data_1.c_str());

                ifstream stock_n("stock/stock_list.txt");
                stock_n.seekg(0, ios::beg);

                for (int i = 0 ; i < count ; i++) {
                    getline(stock_n, data_2);
                }

                n++;
                cout << n << ". " << data_2;

                ifstream stock_v("stock/stock_value.txt");
                stock_v.seekg(0, ios::beg);

                for (int i = 0 ; i < count ; i++) {
                    stock_v >> data_2;
                }

                cout << "\n     Price : " << data_2 << " Baht." << endl;
            }
        }
    } else if (choice == 2) {
        while (stock >> data_1) {
            count++;
            if (data_1[0] == determinants[0] && data_1[1] == determinants[1]) {
                strcpy(stock_id[n], data_1.c_str());

                ifstream stock_n("stock/stock_list.txt");
                stock_n.seekg(0, ios::beg);

                for (int i = 0 ; i < count ; i++) {
                    getline(stock_n, data_2);
                }

                n++;
                cout << n << ". " << data_2;

                ifstream stock_v("stock/stock_value.txt");
                stock_v.seekg(0, ios::beg);

                for (int i = 0 ; i < count ; i++) {
                    stock_v >> data_2;
                }

                cout << "\n     Price : " << data_2 << " Baht." << endl;
            }
        }
    } else if (choice == 3) {
        while (stock >> data_1) {
            count++;
            if (data_1[0] == determinants[0] && data_1[1] == determinants[1] && data_1[2] == determinants[2]) {
                strcpy(stock_id[n], data_1.c_str());

                ifstream stock_n("stock/stock_list.txt");
                stock_n.seekg(0, ios::beg);

                for (int i = 0 ; i < count ; i++) {
                    getline(stock_n, data_2);
                }

                n++;
                cout << n << ". " << data_2;

                ifstream stock_v("stock/stock_value.txt");
                stock_v.seekg(0, ios::beg);

                for (int i = 0 ; i < count ; i++) {
                    stock_v >> data_2;
                }

                cout << "\n     Price : " << data_2 << " Baht." << endl;
            }
        }
    } else if (choice == 4) {
        while (stock >> data_1) {
            count++;
            if (data_1[0] == determinants[0] && data_1[1] == determinants[1] && data_1[2] == determinants[2] && data_1[3] == determinants[3]) {
                strcpy(stock_id[n], data_1.c_str());

                ifstream stock_n("stock/stock_list.txt");
                stock_n.seekg(0, ios::beg);

                for (int i = 0 ; i < count ; i++) {
                    getline(stock_n, data_2);
                }

                n++;
                cout << n << ". " << data_2;

                ifstream stock_v("stock/stock_value.txt");
                stock_v.seekg(0, ios::beg);

                for (int i = 0 ; i < count ; i++) {
                    stock_v >> data_2;
                }

                cout << "\n     Price : " << data_2 << " Baht." << endl;
            }
        }
    }
    
    if (n == 0) {
        cout << "           Out Of Stock !!!!" << endl;
    }

    cout << "---------------------------------------" << endl;
    cout << "---------------------------------------" << endl;
    cout << "1. Add Cart                     " << endl;
    cout << "---------------------------------------" << endl;
    
    while (true) {
        cout << "Enter Here (0 To Exit.) : "; cin >> data_1;

        if (data_1 == "0" || data_1 == "1") {
            break;
        } else {
            cout << "0 Or 1 Only" << endl;
        }
    }

    if (data_1 == "1") {
        if (username != " ") {
            while (true) {
                cout << "Enter Numbers Stock To Add Cart (0 To Exit.) : "; cin >> count;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Please Enter a Number!." << endl;
                } else if (count >= 0 && count <= n) {
                    break;
                } else {
                    cout << "Numbers " << count << " Not Found." << endl;
                }
            }

            if (count >= 1 && count <= n) {
                count = count - 1;

                ifstream stock("stock/stock_id.txt");
                stock.seekg(0, ios::beg);
                choice = 0;

                while (stock >> data_1) {
                    choice++;
                    if (data_1 == stock_id[count]) {
                        break;
                    }
                }

                ifstream stock_l("stock/stock_list.txt");
                stock_l.seekg(0, ios::beg);

                for (int i = 0 ; i < choice ; i++) {
                    getline(stock_l,data_2);
                }

                cout << "You Add " << data_2 << " In Your Cart." << endl;

                data_2 = "user/cart/" + username +".txt";
                ofstream main_cart(data_2, ios::in | ios::out | ios::app);
                main_cart << data_1 << endl;

                data_2 = "junk/user/stock/" + username +".txt";
                ofstream second_cart(data_2, ios::in | ios::out | ios::app);
                second_cart << data_1 << endl;

                ofstream junk_cart("junk/user/cart/cart.txt", ios::trunc);

                ofstream cart_secondary("junk/user/cart/cart.txt");
                ifstream cart_main("user/cart.txt");
                cart_main.seekg(0, ios::beg);
                count = 0;

                while (cart_main >> choice) {
                    count++;
                    if (count == pos) {
                        cart_secondary << choice + 1 << endl;
                    } else {
                        cart_secondary << choice << endl;
                    }
                }

                ofstream cart("user/cart.txt", ios::trunc);

                ifstream cart_secon("junk/user/cart/cart.txt");
                ofstream cart_m("user/cart.txt");

                cart_secon.seekg(0, ios::beg);
                while (cart_secon >> data_1) {
                    cart_m << data_1 << endl;
                }

                Desktop::desktop(data_1, data_2, count, choice, username, pos);
            } else if (count == 0) {
                Desktop::desktop(data_1, data_2, count, 0, username, pos);
            }
        } else {
            cout << "You are not logged in yet." << endl;
            Desktop::desktop(data_1, data_2, count, 0, username, pos);
        }
    } else if (data_1 == "0") {
        Desktop::desktop(data_1, data_2, count, 0, username, pos);
    }
}

void Desktop::case3_list(string data_1, string data_2, int count, int choice, const string username, const int pos, string choose, string word, string data_3) {
    Stock stock;
    string data_4;

    while (true) {
        cout << word; cin >> data_4;

        if (data_4 == "0") {
            break;
        }

        if (choose == "1") {
            if (data_1 == "1") {
                if (data_4 == "1" || data_4 == "2" || data_4 == "3" || data_4 == "4" || data_4 == "5") {
                    break;
                } else {
                    cout << "1 - 5 Only" << endl;
                }
            } else if (data_1 == "2") {
                if (data_4 == "1" || data_4 == "2" || data_4 == "3" || data_4 == "4") {
                    break;
                } else {
                    cout << "1 - 4 Only" << endl;
                }
            }
        } else if (choose == "2") {
            if (data_4 == "1" || data_4 == "2" || data_4 == "3" || data_4 == "4") {
                break;
            } else {
                cout << "1 - 4 Only" << endl;
            }
        } else if (choose == "4") {
            if (data_4 == "1" || data_4 == "2" || data_4 == "3" || data_4 == "4") {
                break;
            } else {
                cout << "1 - 4 Only" << endl;
            }
        } else if (choose == "5") {
            if (data_4 == "1" || data_4 == "2" || data_4 == "3" || data_4 == "4" || data_4 == "5") {
                break;
            } else {
                cout << "1 - 5 Only" << endl;
            }
        }
    }

    if (data_4 == "0") {
        Desktop::desktop(data_1, data_2, count, choice, username, pos);
    } else if ((choose == "1" && data_4 == "5" && data_1 == "1") || (choose == "2" && data_4 == "4") || (choose == "4" && data_4 == "4") || (choose == "5" && data_4 == "5") || (choose == "1" && data_4 == "4" && data_1 == "2")) {
        choice = 3;
        stock.show_stock(data_1, data_2, count, choice, username, pos);
    } else {
        choice = 4;
        data_2 += data_4;
        stock.show_stock(data_1, data_2, count, choice, username, pos);
    }
}

void Desktop::case2_list(string data_1, string data_2, int count, int choice, const string username, const int pos, string choose, string word) {
    Stock stock;
    string data_3;

    while (true) {
        cout << word ; cin >> data_3;

        if (data_3 == "0") {
            break;
        }

        if (choose == "1" && (data_1 == "1" || data_1 == "2")) {
            if (data_3 == "1" || data_3 == "2" || data_3 == "3" || data_3 == "4") {
                break;
            } else {
                cout << "1 - 4 Only" << endl;
            }
        } else if (choose == "2" && (data_1 == "1" || data_1 == "2" || data_1 == "3")) {
            if (data_3 == "1" || data_3 == "2" || data_3 == "3" || data_3 == "4" || data_3 == "5") {
                break;
            } else {
                cout << "1 - 5 Only" << endl;
            }
        } else if (choose == "3" && (data_1 == "1" || data_1 == "2" || data_1 == "3")) {
            if (data_3 == "1" || data_3 == "2" || data_3 == "3" || data_3 == "4" || data_3 == "5" || data_3 == "6") {
                break;
            } else {
                cout << "1 - 6 Only" << endl;
            }
        } else if (choose == "4" && (data_1 == "1" || data_1 == "2")) {
            if (data_3 == "1" || data_3 == "2" || data_3 == "3" || data_3 == "4") {
                break;
            } else {
                cout << "1 - 4 Only" << endl;
            }
        } else if (choose == "5" && (data_1 == "1" || data_1 == "2")) {
            if (data_3 == "1" || data_3 == "2" || data_3 == "3") {
                break;
            } else {
                cout << "1 - 3 Only" << endl;
            }
        } else if (choose == "6" && (data_1 == "1" || data_1 == "2" || data_1 == "3" || data_1 == "4")) {
            if (data_3 == "1" || data_3 == "2" || data_3 == "3" || data_3 == "4" || data_3 == "5" || data_3 == "6") {
                break;
            } else {
                cout << "1 - 6 Only" << endl;
            }
        }
    }

    if (choose == "1" && data_1 == "1" && data_3 == "1") {
        word = "CPU Intel Generation 14 Filter \n1. Core I9   2. Core I7   3. Core I5   4. Core I3   5. All \nEnter Here : ";
    } else if (choose == "1" && data_1 == "1" && data_3 == "2") {
        word = "CPU Intel Generation 13 Filter \n1. Core I9   2. Core I7   3. Core I5   4. Core I3   5. All \nEnter Here : ";
    } else if (choose == "1" && data_1 == "1" && data_3 == "3") {
        word = "CPU Intel Generation 12 Filter \n1. Core I9   2. Core I7   3. Core I5   4. Core I3   5. All \nEnter Here : ";
    } else if (choose == "1" && data_1 == "2" && data_3 == "1") {
        word = "CPU AMD 8000 Series Filter \n1. Ryzen 9   2. Ryzen 7   3. Ryzen 5   4. All \nEnter Here : ";
    } else if (choose == "1" && data_1 == "2" && data_3 == "2") {
        word = "CPU AMD 7000 Series Filter \n1. Ryzen 9   2. Ryzen 7   3. Ryzen 5   4. All \nEnter Here : ";
    } else if (choose == "1" && data_1 == "2" && data_3 == "3") {
        word = "CPU AMD 5000 Series Filter \n1. Ryzen 9   2. Ryzen 7   3. Ryzen 5   4. All \nEnter Here : ";
    } else if (choose == "2" && data_1 == "1" && data_3 == "1") {
        word = "Mainboard Gigabyte AM5 List \n1. ATX   2. Micro-ATX   3. E-ATX   4. All \nEnter Here : ";
    } else if (choose == "2" && data_1 == "1" && data_3 == "2") {
        word = "Mainboard Gigabyte AM4 List \n1. ATX   2. Micro-ATX   3. E-ATX   4. All \nEnter Here : ";
    } else if (choose == "2" && data_1 == "1" && data_3 == "3") {
        word = "Mainboard Gigabyte LGA-1700 List \n1. ATX   2. Micro-ATX   3. E-ATX   4. All \nEnter Here : ";
    } else if (choose == "2" && data_1 == "1" && data_3 == "4") {
        word = "Mainboard Gigabyte LGA-1200 List \n1. ATX   2. Micro-ATX   3. E-ATX   4. All \nEnter Here : ";
    } else if (choose == "2" && data_1 == "2" && data_3 == "1") {
        word = "Mainboard MSI AM5 List \n1. ATX   2. Micro-ATX   3. E-ATX   4. All \nEnter Here : ";
    } else if (choose == "2" && data_1 == "2" && data_3 == "2") {
        word = "Mainboard MSI AM4 List \n1. ATX   2. Micro-ATX   3. E-ATX   4. All \nEnter Here : ";
    } else if (choose == "2" && data_1 == "2" && data_3 == "3") {
        word = "Mainboard MSI LGA-1700 List \n1. ATX   2. Micro-ATX   3. E-ATX   4. All \nEnter Here : ";
    } else if (choose == "2" && data_1 == "2" && data_3 == "4") {
        word = "Mainboard MSI LGA-1200 List \n1. ATX   2. Micro-ATX   3. E-ATX   4. All \nEnter Here : ";
    } else if (choose == "2" && data_1 == "3" && data_3 == "1") {
        word = "Mainboard ASUS AM5 List \n1. ATX   2. Micro-ATX   3. E-ATX   4. All \nEnter Here : ";
    } else if (choose == "2" && data_1 == "3" && data_3 == "2") {
        word = "Mainboard ASUS AM4 List \n1. ATX   2. Micro-ATX   3. E-ATX   4. All \nEnter Here : ";
    } else if (choose == "2" && data_1 == "3" && data_3 == "3") {
        word = "Mainboard ASUS LGA-1700 List \n1. ATX   2. Micro-ATX   3. E-ATX   4. All \nEnter Here : ";
    } else if (choose == "2" && data_1 == "3" && data_3 == "4") {
        word = "Mainboard ASUS LGA-1200 List \n1. ATX   2. Micro-ATX   3. E-ATX   4. All \nEnter Here : ";
    } else if (choose == "4" && data_1 == "1" && data_3 == "1") {
        word = "RAM DDR5 Corsair List \n1. 3200Mhz   2. 3600Mhz   3. 5200-5600Mhz   4. All\nEnter Here : ";
    } else if (choose == "4" && data_1 == "1" && data_3 == "2") {
        word = "RAM DDR4 Corsair List \n1. 3200Mhz   2. 3600Mhz   3. 5200-5600Mhz   4. All\nEnter Here : ";
    } else if (choose == "4" && data_1 == "1" && data_3 == "1") {
        word = "RAM DDR5 Kingston List \n1. 3200Mhz   2. 3600Mhz   3. 5200-5600Mhz   4. All\nEnter Here : ";
    } else if (choose == "4" && data_1 == "1" && data_3 == "2") {
        word = "RAM DDR4 Kingston List \n1. 3200Mhz   2. 3600Mhz   3. 5200-5600Mhz   4. All\nEnter Here : ";
    } else if (choose == "4" && data_1 == "1" && data_3 == "1") {
        word = "RAM DDR5 G.Skill List \n1. 3200Mhz   2. 3600Mhz   3. 5200-5600Mhz   4. All\nEnter Here : ";
    } else if (choose == "4" && data_1 == "1" && data_3 == "2") {
        word = "RAM DDR4 G.Skill List \n1. 3200Mhz   2. 3600Mhz   3. 5200-5600Mhz   4. All\nEnter Here : ";
    } else if (choose == "5" && data_1 == "1" && data_3 == "1") {
       word = "SSD M.2 Kingston List \n1. 1TB   2. 500GB   3. 480GB   4. 256GB   5. All \nEnter Here : ";
    } else if (choose == "5" && data_1 == "1" && data_3 == "2") {
       word = "SSD M.2 Apacer List \n1. 1TB   2. 500GB   3. 480GB   4. 256GB   5. All \nEnter Here : ";
    } else if (choose == "5" && data_1 == "2" && data_3 == "1") {
       word = "SSD SATA Kingston List \n1. 1TB   2. 500GB   3. 480GB   4. 256GB   5. All \nEnter Here : ";
    } else if (choose == "5" && data_1 == "2" && data_3 == "2") {
       word = "SSD SATA Apacer List \n1. 1TB   2. 500GB   3. 480GB   4. 256GB   5. All \nEnter Here : ";
    } else {
        choice = 2;
    }
    

    if (choice == 0) {
        data_2 += data_3;
        case3_list(data_1, data_2, count, choice, username, pos, choose, word, data_3);
    } else if (data_3 == "0") {
        Desktop::desktop(data_1, data_2, count, choice, username, pos);
    } else if (choose == "3" && (data_3 == "1" || data_3 == "2" || data_3 == "3" || data_3 == "4" || data_3 == "5") || choose == "6" && (data_3 == "1" || data_3 == "2" || data_3 == "3" || data_3 == "4" || data_3 == "5")) {
        data_2 += data_3;
        choice = 3;
        stock.show_stock(data_1, data_2, count, choice, username, pos);
    } else {
        stock.show_stock(data_1, data_2, count, choice, username, pos);
    }

}

void Desktop::case_list(string data_1, string data_2, int count, int choice, const string username, const int pos, string choose) {
    Stock stock;
    string word;
    data_2 = choose;
    choice = 0;

    if (choose == "1") {
        word = "CPU Filter \n1. Intel   2. AMD   3. All \nEnter Here : ";
    } else if (choose == "2") {
        word = "Mainboard List \n1. Gigabyte   2. MSI   3. ASUS   4. All \nEnter Here : ";
    } else if (choose == "3") {
        word = "GPU List \n1. Gigabyte   2. ASUS   3. MSI   4. All \nEnter Here : ";
    } else if (choose == "4") {
        word = "Ram List \n1. DDR5   2. DDR4   3. All \nEnter Here : ";
    } else if (choose == "5") {
        word = "SSD List \n1. M.2   2. SATA   3. All \nEnter Here : ";
    } else if (choose == "6") {
        word = "Power Supply List \n1. Gigabyte   2. MSI   3. Thermaltake   4. Corsair    5. All\nEnter Here : ";
    }

    while (true) {
        cout << word ;cin >> data_1;

        if (data_1 == "0") {
            break;
        }    

        if (choose == "1") {
            if (data_1 == "1" || data_1 == "2" || data_1 == "3") {
                break;
            } else {
                cout << "1 - 3 Only" << endl;
            }
        } else if (choose == "2") {
            if (data_1 == "1" || data_1 == "2" || data_1 == "3" || data_1 == "4") {
                break;
            } else {
                cout << "1 - 4 Only" << endl;
            }
        } else if (choose == "3") {
            if (data_1 == "1" || data_1 == "2" || data_1 == "3" || data_1 == "4") {
                break;
            } else {
                cout << "1 - 4 Only" << endl;
            }
        } else if (choose == "4") {
            if (data_1 == "1" || data_1 == "2" || data_1 == "3") {
                break;
            } else {
                cout << "1 - 3 Only" << endl;
            }
        } else if (choose == "5") {
            if (data_1 == "1" || data_1 == "2" || data_1 == "3") {
                break;
            } else {
                cout << "1 - 3 Only" << endl;
            }
        } else if (choose == "6") {
            if (data_1 == "1" || data_1 == "2" || data_1 == "3" || data_1 == "4" || data_1 == "5") {
                break;
            } else {
                cout << "1 - 5 Only" << endl;
            }
        }
    }

    if (choose == "1" && data_1 == "1") {
        word = "CPU Intel Filter \n1. Generation 14   2. Generation 13   3. Generation 12   4. All \nEnter Here : ";
    } else if (choose == "1" && data_1 == "2") {
        word = "CPU AMD Filter \n1. 8000 Series   2. 7000 Series   3. 5000 Series   4. All \nEnter Here : ";
    } else if (choose == "2" && data_1 == "1") {
        word = "Mainboard Gigabyte List \n1. AM5   2. AM4   3. LGA-1700   4. LGA-1200   5. All\nEnter Here : ";
    } else if (choose == "2" && data_1 == "2") {
        word = "Mainboard ASUS List \n1. AM5   2. AM4   3. LGA-1700   4. LGA-1200   5. All\nEnter Here : ";
    } else if (choose == "2" && data_1 == "3") {
        word = "Mainboard MSI List \n1. AM5   2. AM4   3. LGA-1700   4. LGA-1200   5. All\nEnter Here : ";
    } else if (choose == "3" && data_1 == "1") {
        word = "GPU Gigabyte List \n1. NVIDIA 4000 Series   2. NVIDIA 3000 Series   3. NVIDIA 2000 Series   4. AMD 7000 Series   5. AMD 6000 Series   6. All\nEnter Here : ";
    } else if (choose == "3" && data_1 == "2") {
        word = "GPU ASUS List \n1. NVIDIA 4000 Series   2. NVIDIA 3000 Series   3. NVIDIA 2000 Series   4. AMD 7000 Series   5. AMD 6000 Series   6. All\nEnter Here : ";
    } else if (choose == "3" && data_1 == "3") {
        word = "GPU MSI List \n1. NVIDIA 4000 Series   2. NVIDIA 3000 Series   3. NVIDIA 2000 Series   4. AMD 7000 Series   5. AMD 6000 Series   6. All\nEnter Here : ";
    } else if (choose == "4" && data_1 == "1") {
        word = "RAM DDR5 List \n1. Corsair   2. Kingston   3. G.Skill   4. All\nEnter Here : ";
    } else if (choose == "4" && data_1 == "2") {
        word = "RAM DDR4 List \n1. Corsair   2. Kingston   3. G.Skill   4. All\nEnter Here : ";
    } else if (choose == "5" && data_1 == "1") {
        word = "SSD M.2 List \n1. Kingston   2. Apacer   3. All\nEnter Here : ";
    } else if (choose == "5" && data_1 == "2") {
        word = "SSD SATA List \n1. Kingston   2. Apacer   3. All\nEnter Here : ";
    } else if (choose == "6" && data_1 == "1") {
        word = "Power Supply Gigabyte List \n1. 1200W   2. 1000W   3. 850W   4. 750W   5. 550W   6. All\nEnter Here : ";
    } else if (choose == "6" && data_1 == "2") {
        word = "Power Supply Msi List \n1. 1200W   2. 1000W   3. 850W   4. 750W   5. 550W   6. All\nEnter Here : ";
    } else if (choose == "6" && data_1 == "3") {
        word = "Power Supply Thermaltake List \n1. 1200W   2. 1000W   3. 850W   4. 750W   5. 550W   6. All\nEnter Here : ";
    } else if (choose == "6" && data_1 == "4") {
        word = "Power Supply Corsair List \n1. 1200W   2. 1000W   3. 850W   4. 750W   5. 550W   6. All\nEnter Here : ";
    } else {
        choice = 1;
    }

    if (choice == 0 && data_1 != "0") {
        data_2 += data_1;
        case2_list(data_1, data_2, count, choice, username, pos, choose, word);
    } else if (data_1 == "0") {
        Desktop::desktop(data_1, data_2, count, choice, username, pos);
    } else {
        stock.show_stock(data_1, data_2, count, choice, username, pos);
    }
}

void conti(string data_1, string data_2, int count, int choice, const string username, const int pos) {
    string choose;
    Desktop deskstop;
    switch (choice) {
        Stock stock;
        case 1:
            choose = "1";
            deskstop.case_list(data_1, data_2, count, choice, username, pos, choose);
            break;
        case 2:
            choose = "2";
            deskstop.case_list(data_1, data_2, count, choice, username, pos, choose);
            break;
        case 3:
            choose = "3";
            deskstop.case_list(data_1, data_2, count, choice, username, pos, choose);
            break;
        case 4:
            choose = "4";
            deskstop.case_list(data_1, data_2, count, choice, username, pos, choose);
            break;
        case 5:
            choose = "5";
            deskstop.case_list(data_1, data_2, count, choice, username, pos, choose);
            break;
        case 6:
            choose = "6";
            deskstop.case_list(data_1, data_2, count, choice, username, pos, choose);
            break;
        case 7:
            Cart cart;
            cart.show_cart(data_1, data_2, count, choice, username, pos); 
            break;
        case 8:
            Login(data_1, data_2, count, username);
            break;
        case 9: 
            if (username == " ") {
                Register(data_1, data_2, count);
                break;
            } else {
                Desktop desktop;
                desktop.Change(data_1, data_2, username, pos, count);
                break;
            }
            break;
    }
}
