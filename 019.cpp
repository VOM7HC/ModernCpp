#include <format>
#include <iostream>
#include <regex>

using namespace std;

int main()
{

    regex r1("02215");
    cout << "Matching against: 02215\n"
         << format("02215: {}; 51220: {}\n\n",
                regex_match("02215", r1), regex_match("51220", r1));

    regex r2(R"(\d{5})");
    cout << R"(Matching against: \d{5})"
         << "\n"
         << format("02215: {}; 9876: {}\n\n",
                regex_match("02215", r2), regex_match("9876", r2));

    regex r3("[A-Z][a-z]*");
    cout << "Matching against: [A-Z][a-z]*\n"
         << format("Wally: {}; eva: {}\n\n",
                regex_match("Wally", r3), regex_match("eva", r3));

    regex r4("[^a-z]");
    cout << "Matching against: [^a-z]\n"
         << format("A: {}; a: {}\n\n",
                regex_match("A", r4), regex_match("a", r4));

    regex r5("[*+$]");
    cout << "Matching against: [*+$]\n"
         << format("*: {}; !: {}\n\n",
                regex_match("*", r5), regex_match("!", r5));

    regex r6("[A-Z][a-z]+");
    cout << "Matching against: [A-Z][a-z]+\n"
         << format("Wally: {}; E: {}\n\n",
                regex_match("Wally", r6), regex_match("E", r6));

    regex r7("labell?ed");
    cout << "Matching against: labell?ed\n"
         << format("labelled: {}; labeled: {}; labellled: {}\n\n",
                regex_match("labelled", r7), regex_match("labeled", r7),
                regex_match("labellled", r7));

    regex r8(R"(\d{3,})");
    cout << R"(Matching against: \d{3,})"
         << "\n"
         << format("123: {}; 1234567890: {}; 12: {}\n\n",
                regex_match("123", r8), regex_match("1234567890", r8),
                regex_match("12", r8));

    regex r9(R"(\d{3,6})");
    cout << R"(Matching against: \d{3,6})"
         << "\n"
         << format("123: {}; 123456: {}; 1234567: {}; 12: {}\n",
                regex_match("123", r9), regex_match("123456", r9),
                regex_match("1234567", r9), regex_match("12", r9));
}
