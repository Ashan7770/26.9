#include <iostream>
#include <string>
#include <thread>
#include <ctime>
using namespace std;
int write_msg(int msg)
{
    cout << msg << std::endl;
    return msg;
}
int write_msq(int msq)
{
    cout << msq << std::endl;
    return msq;
}
int main()
{
    srand(time(NULL));
    const int pam = 8;
    srand(time(NULL));
    int mass[pam] = {};
    for (int rr = 0; rr < pam; rr++) {
        mass[rr] = rand() % 10 + 1;
        cout << mass[rr] << endl;
    }
    cout << "____________________" << endl;
    int c,d;
  thread t(write_msg, c=(mass[0]+ mass[1] + mass[2] + mass[3]));
  thread q(write_msq, d = (mass[4] + mass[5] + mass[6] + mass[7]));
  thread r(write_msq, c + d);
    t.join();
    q.join();
    r.join();  
    return 0;
}