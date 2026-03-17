#include <iostream>
using namespace std;

int main()
{
    char data[100];
    int count = 0;

    cout << "Enter data: ";
    cin >> data;

    while(data[count] != '\0')
        count++;

    cout << "Frame transmitted: ";
    cout << count << data;

    return 0;
}


// #include <iostream>
// using namespace std;

// int main()
// {
//     char data[100];
//     int i;

//     cout << "Enter data: ";
//     cin >> data;

//     cout << "Frame after character stuffing:\n";
//     cout << "DLE STX ";

//     for(i=0; data[i] != '\0'; i++)
//     {
//         if(data[i] == 'D')   // assuming D represents DLE
//             cout << "DD";
//         else
//             cout << data[i];
//     }

//     cout << " DLE ETX";

//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int data[100], stuffed[200];
//     int n, i, j = 0, count = 0;

//     cout << "Enter number of bits: ";
//     cin >> n;

//     cout << "Enter bits:\n";
//     for(i=0;i<n;i++)
//         cin >> data[i];

//     for(i=0;i<n;i++)
//     {
//         stuffed[j] = data[i];
//         j++;

//         if(data[i] == 1)
//         {
//             count++;
//             if(count == 5)
//             {
//                 stuffed[j] = 0;
//                 j++;
//                 count = 0;
//             }
//         }
//         else
//             count = 0;
//     }

//     cout << "After bit stuffing:\n";

//     for(i=0;i<j;i++)
//         cout << stuffed[i];

//     return 0;
// }