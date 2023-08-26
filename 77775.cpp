 #include <iostream>
using namespace std;

class A{
public:
    A(int a, int b, int c);
private:
    int m_a;
    int m_b;
    int m_c;
};
A::A(int a, int b, int c): m_a(a), m_b(b), m_c(c){ }

int main(){
    A obj(10, 20, 30);
    int a1 = *(int*)&obj;
    int b = (long long)(int*)( (long long)&obj + sizeof(int) );
    cout<<&obj<<endl;
    cout<<&obj+ sizeof(int)<<endl;
    cout<<(long long)&obj  + sizeof(int)<<endl;
    cout<<a1<<endl;
    cout<<b;
    }