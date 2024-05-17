#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <locale>
#include <codecvt>
#include <Windows.h>
#include <ctime>

//int levenshtein_distance(const std::string& s1, const std::string& s2) {
//    const size_t m = s1.length();
//    const size_t n = s2.length();
//
//    if (m == 0) {
//        return n;
//    }
//
//    if (n == 0) {
//        return m;
//    }
//
//    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
//
//    for (size_t i = 0; i <= m; ++i) {
//        dp[i][0] = i;
//    }
//
//    for (size_t j = 0; j <= n; ++j) {
//        dp[0][j] = j;
//    }
//
//    for (size_t i = 1; i <= m; ++i) {
//        for (size_t j = 1; j <= n; ++j) {
//            if (s1[i - 1] == s2[j - 1]) {
//                dp[i][j] = dp[i - 1][j - 1];
//            }
//            else {
//                dp[i][j] = 1 + std::min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
//            }
//        }
//    }
//
//    return dp[m][n];
//}
//
//void quick_sort(std::vector<int>& arr, int left, int right) {
//    if (left >= right) {
//        return;
//    }
//
//    int pivot_index = left;
//    int pivot_value = arr[pivot_index];
//
//    int i = left + 1;
//    int j = right;
//
//    while (true) {
//        while (i <= right && arr[i] <= pivot_value) {
//            i++;
//        }
//
//        while (j >= left + 1 && arr[j] > pivot_value) {
//            j--;
//        }
//
//        if (i >= j) {
//            break;
//        }
//
//        std::swap(arr[i], arr[j]);
//    }
//
//    std::swap(arr[pivot_index], arr[j]);
//    pivot_index = j;
//
//    quick_sort(arr, left, pivot_index - 1);
//    quick_sort(arr, pivot_index + 1, right);
//}
//
//void quick_sort(std::vector<int>& arr) {
//    quick_sort(arr, 0, arr.size() - 1);
//}

void read_words_from_file(const std::string& filename, std::vector<std::string>& all_words) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string word;
        while (std::getline(iss, word, ';')) {
            all_words.push_back(word);
        }
    }

    file.close();
}


class Banned_Words
{
//private:
public:
    int word_index;
    std::string banned_word;
    std::string author_word; // Who add this word
    std::string comment;
    time_t time_added;

    Banned_Words(int index, std::string word, std::string add_comment = "")
    {
        word_index = 1;
        banned_word = "working";
        author_word = "System";
        time_added = time(nullptr);
        comment = add_comment;
        std::cout << "Class created with parameters...\n";
    }

    Banned_Words() {
        word_index = 0;
        banned_word = "";
        author_word = "System";
        time_added = time(nullptr);
        std::cout << "Dafault const...\n";
    }
    

    void Add_Word(std::string text)
    {
        banned_word = text;
        std::cout << "Word added...";
    }
    void Add_Word()
    {
        std::cout << "Default func\n";
    }

    void Print_word()
    {
        std::cout << word_index;
        std::cout << banned_word;
        std::cout << author_word;
        std::cout << time_added;
        std::cout << comment;
    }
};

//Banned_Words obj = Banned_Words();
//Banned_Words* obj1 = new Banned_Words(1, "word", "author");
//Banned_Words obj2 = Banned_Words(1, "word", "by MooDuckChe");
//Banned_Words** obj4 = new Banned_Words * [5];




////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////         DataBase        /////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
std::vector<std::string> all_words;
std::vector<std::string> banned_words = { "chebugram", "I", "apple", "working"};
std::vector<std::pair<std::string, std::string>> database_user = {
    {"MooDuckChe", "1234"},
    {"Aviron",     "5678"},
    {"def4oult",   "7890"}
};

////////////////////////////////////////////////////////////////////////////////////////////////////////

void Initzialization_Banned_Word()
{
    int n = 5; // размер массива

    // Создание динамического массива указателей на объекты класса Banned_Words
    Banned_Words** obj_array = new Banned_Words * [n];

    // Выделение памяти для каждого объекта класса Banned_Words и инициализация его параметрами
    for (int i = 0; i < n; i++)
    {
        obj_array[i] = new Banned_Words(i + 1, banned_words[i]);
        Sleep(1000);
    }
}

void Add_new_block_word(std::string word)
{
    //Banned_Words obj = Banned_Words();

    //obj.Add_Word(word);

    //banned_words.push_back(word);
}

void Out_String(std::vector<std::string> text)
{
    for (const auto& word : all_words) {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        std::wstring wide_word = converter.from_bytes(word);
        std::wcout << wide_word << L"; ";
    }
}

void Print_banned_words()
{
    for (int i = 0; i < banned_words.size(); i++)
        std::cout << "[" << i + 1 << "]" << banned_words[i] << std::endl;
}

int Check_String_On_Banned_Word(std::vector<std::string> message, long long int message_id)
{
    int count_ban_word = 0;
    for (int i = 0; i < message.size(); i++)
        for (int j = 0; j < banned_words.size(); j++)
            if (message[i] == banned_words[j])
                count_ban_word++;

    if (count_ban_word)
        std::cout << "Message #" << message_id << " has " << count_ban_word << " banned word.\n";
    else
        std::cout << "Message #" << message_id << " does not contain any banned words.\n";
    return count_ban_word;
}

std::vector<std::string> Separate_and_clear_space_message(std::string& message)
{
    std::vector<std::string> message_separated;
    std::string word;
    int k = 0;
    while (message[message.size() - 1] == ' ')
        message.resize(message.size() - 1);
    message += ' ';
    for (int i = 0; i <= message.size(); i++)
    {
        if (message[i] == ' ')
        {
            message_separated.push_back(word);
            word = "";
            continue;
        }
        word += message[i];
    }

    return message_separated;
}

void Main_Menu()
{
    std::vector<std::string> menu_str = {
        "[1] Print all words.",
        "[2] Print banned words.",
        "[3] Print banned word index (need fix)",
        "[4] Print added banned words (need fix)", // Who when what
        "[5] Print deleted words (need fix)\n",

        "[6] Add new block word. (need fix)",
        "[7] Delete block word. (need fix)",
        "[8] Count block words. (need fix)\n",
        
        "[0] Exit"

    };
    for (int i = 0; i < menu_str.size(); i++)
        std::cout << menu_str[i] << std::endl;
    for (int i = 0; i < 7; i++)
        std::cout << std::endl;
    std::cout << "Select #";
}

bool Valid_Data(std::string user, std::string password)
{
    for (int i = 0; i < database_user.size(); i++)
        if (database_user[i].first == user && database_user[i].second == password)
            return true;
    return false;
}

bool Verification(std::string user, std::string password)
{
    // bool admin = true/false
    return (Valid_Data(user, password) ? true : false);
}

void Switch(int choose, int& delay, bool& flag, std::string& send_string)
{
    // Switch user
    // Add user
    switch (choose)
    {
        // Print all words
    case 1:
    {
        Out_String(all_words);
        break;
    }
    // Print banned words.
    case 2:
    {
        Print_banned_words();
        break;
    }
    // Print banned word index
    case 3:
    {
        break;
    }
    // Print added banned words
    case 4:
    {
        break;
    }
    // Print deleted words
    case 5:
    {
        break;
    }
    // Add new baned word
    case 6:
    {
        std::cout << "Введите слово: ";
        std::string new_word;
        std::cin >> new_word;
        std::cout << "Вы добавили слово: " << new_word << std::endl;
        Add_new_block_word(new_word);
        break;
    }
    // Delete word
    case 7:
    {
        break;
    }
    // Count banned word
    case 8:
    {
        std::vector<std::string> message = Separate_and_clear_space_message(*&send_string);
        Check_String_On_Banned_Word(*&message, 20132148124);
        break;
    }
    case 0:
    {
        flag = false;
        std::cout << "\nExiting";
        for (int i = 0; i < 3; std::cout << '.', Sleep(200), i++);
        delay = 0;
        break;
    }
    }
}

int main()
{
    // строка   
    // Установить локаль для консоли
    std::locale::global(std::locale(""));
    std::wcout.imbue(std::locale());
    system("chcp 1251 > nul");

    const std::string all_words_file = "sample.txt";
    read_words_from_file(all_words_file, all_words);

    std::string send_string = "I am working on chebugram with many space            and space between";

    std::string user, password;
    std::cout << "User: ";
    std::cin >> user;
    std::cout << "Password: ";
    std::cin >> password;
    system("cls");

    if (!(Verification(user, password)))
    {
        std::cout << "Invalid user or password";
        return 0;
    }
    
    int choose = 0;
    bool flag = true;
    int delay = 3000;
    while (flag)
    {
        Main_Menu();
        std::cin >> choose;
        Switch(choose, *&delay, *&flag, *&send_string);
        Sleep(delay);
        system("cls");
    }
    return 0;
}