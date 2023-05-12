#include <iostream>
#include <fstream>
#include <cstring>
#include<ctime>
#include<chrono>

using namespace std;
ofstream fout ("/Users/marius/CLionProjects/Cripto_project/output.txt");

long long numbers[3];
long long primes[10001];
long long n = 1;
int k = 0;

struct {
    int number;
    int fr;

} freq[300];
void init_numbers(){
    n = 1;

    numbers[1] = 7;
    numbers[2] = 0;

    for(int i = 1;i<10000;i++)
        primes[i] = -1;
}

void init_freq(){

    for(int i = 0; i < 300; i++){
        freq[i].number = 0;
        freq[i].fr = 0;
    }
}

bool isPrime(int x){
    if(x == 2) return 1;
    if(x%2==0) return 0;

    for(int i = 3;i*i<=x;i=i+2)
        if(x%i == 0)
            return 0;
    return 1;
}

long gcd(long long a,long long b) {
    long long R;

    while ((a % b) > 0)  {
        R = a % b;
        a = b;
        b = R;
    }

    return b;
}
void printInfoAboutNumber(int maxLimit){
    init_numbers();

    while(n < maxLimit){
        n++;
        long long x = numbers[1];
        numbers[2] = x + gcd(x,n);

        if(numbers[2] - numbers[1] != 1)
            primes[k++] = numbers[2] - numbers[1];

        numbers[1] = numbers[2];
    }

    fout<<"Am gasit urmatoarele numere prime"<<endl;

    for(int j = 0;j<10000;j++)
        if(primes[j] != -1)
            fout<<primes[j]<<" ";

    fout<<endl;

    init_freq();
    int k = 0;

    for(int i = 0;i<10000-1;i++)
        for(int j = i;j <10000; j++)
            if(primes[i]!=-1 && primes[j]!=-1)
                if(primes[i] > primes[j])
                    swap(primes[i],primes[j]);
    int i = 0;

    while(primes[i] != -1){
        int x = primes[i];
        int fre = 1;

        while(x == primes[i+1] && primes[i+1] != -1){
            fre++;
            i++;
        }

        freq[k].number = x;
        freq[k].fr = fre;

        k++, i++;
    }

    fout<<"===================="<<endl;
    fout<<"Frecventa numerelor este: "<<endl;

    for(int i = 0;i<k;i++)
        fout<<"Numarul "<< freq[i].number << " are freceventa de "<<freq[i].fr<<endl;

    fout<<endl<<"===================="<<endl;

    int Primes = 0;
    int nonPrimes = 0;

    for(int j = 0; j<k;j++)
        if(isPrime(freq[j].number))
            Primes++;
        else nonPrimes++;

    double prob = Primes/(Primes + nonPrimes);

    fout<<"Probabilitatea ca toate numere gasite sa fie prime este: "<<prob*100<<" %"<<endl;

}

void primeNumbersLessThanN(int maxLimit){
    init_numbers();

    while(n < maxLimit){
        n++;
        long long x = numbers[1];

        numbers[2] = x + gcd(x,n);

        if(numbers[2] - numbers[1] != 1)
            primes[k++] = numbers[2] - numbers[1];

        numbers[1] = numbers[2];
    }

    cout<<endl<<"Am terminat de gasit numerele prime din seceventa de numere mai mici decat "<<maxLimit<<endl;

    for(int i = 1;i<1000;i++)
        if(primes[i] != -1)
            fout<<"Numarul "<<i<<" este: "<<primes[i]<<endl;

    fout<<endl<<"===================="<<endl;

}

long long maxBase2 = pow(2,32) - 1;

void maxIntPrimes(){
    init_numbers();

    while(n < maxBase2) { // INT32_MAX
        n++;
        long long x = numbers[1];

        numbers[2] = x + gcd(x, n);
        if (numbers[2] - numbers[1] != 1)
            primes[k++] = numbers[2] - numbers[1];

        numbers[1] = numbers[2];
    }

    cout<<endl<<"Am terminat de gasit numerele prime din seceventa de numere mai mici decat "<<INT32_MAX<<endl;

    for(int i = 1;i<1000;i++)
        if(primes[i] != -1)
            fout<<"Numarul "<<i<<" este: "<<primes[i]<<endl;

    fout<<"===================="<<endl;

}

void freqNumbers( int maxLimit){
    primeNumbersLessThanN(maxLimit);
    init_freq();

    int k = 0;
    for(int i = 0;i<10000-1;i++)
        for(int j = i;j <10000; j++)
            if(primes[i]!=-1 && primes[j]!=-1)
                if(primes[i] > primes[j])
                    swap(primes[i],primes[j]);
    int i = 0;
    while(primes[i] != -1){
       int x = primes[i];
       int fre = 1;

       while(x == primes[i+1] && primes[i+1] != -1){
           fre++;
           i++;
       }

       freq[k].number = x;
       freq[k].fr = fre;
       k++,i++;

   }

    for(int i = 0;i<k;i++)
        cout<<"Numarul "<< freq[i].number << " are freceventa de "<<freq[i].fr<<endl;

    cout<<endl<<"===================="<<endl;

}

void execRaport(int maxLimit){
    primeNumbersLessThanN(maxLimit);

    int cnt = 0;

    for(int i = 0; i< 10000;i++)
        if(primes[i] != -1)
            cnt++;

    cout<<"Am gasit "<<cnt<<" numere prime mai mici decat "<<n<<endl;

    cout<<"Raportul este "<<(double)cnt/n <<" %"<<endl;

    cout<<endl<<"===================="<<endl;

}

void outputIsPrime(int maxLimit){
    primeNumbersLessThanN(maxLimit);

    for(int i = 0;i<10000;i++) {
        if (primes[i] != -1) {
            if (isPrime(primes[i])) {
                cout << "Numarul " << primes[i] << " este prim" << endl;
            } else {
                cout << "Numarul " << primes[i] << " nu este prim" << endl;
            }
        }
    }

    cout<<endl<<"===================="<<endl;

}

void primeNumbers(int maxLimit){
    primeNumbersLessThanN(maxLimit);

    cout<<"===================="<<endl;

    int k =0;
    for(int i = 0;i<10000;i++)
        if(primes[i]!=-1)
            k++;

    int cnt = 0;

    for(int i = 2;i<=maxLimit;i++)
        if(isPrime(i))
            cnt++;

    cout<<"Avem "<<cnt<<" numere prime mai mici decat "<<maxLimit<<endl;

    cout<<"Numerele prime gasite in algoritm sunt "<<k<<endl;

    cout<<"Am gasit "<<(double)k/cnt <<"% din numarul total de numere prime"<<endl;

    cout<<"Am omis " << cnt -k <<" numere prime"<<endl;

    cout<<"===================="<<endl;

}

void accuracy(int maxLimit){
    cout<<"===================="<<endl;

    primeNumbersLessThanN(maxLimit);

    int Primes = 0;
    int nonPrimes = 0;

    for(int i = 0;i<10000;i++) {
        if (primes[i] != -1) {
            if (isPrime(primes[i])) {
                Primes++;
            } else nonPrimes++;
        }
    }

    if(nonPrimes > 0)
        cout<<"Avem "<<nonPrimes<<" numere gasite care nu sunt prime"<<endl;

    double prob = Primes/(Primes + nonPrimes);

    cout<<"Probabilitatea ca toate numere gasite sa fie prime este: "<<prob*100<<" %"<<endl;

    cout<<"===================="<<endl;

}

void timeMaxedNumber(int maxLimit){

    auto beginSeq = std::chrono::high_resolution_clock::now();
    primeNumbersLessThanN(maxLimit);
    auto endSeq = std::chrono::high_resolution_clock::now();

    auto elapsedSeq = std::chrono::duration_cast<std::chrono::nanoseconds>(endSeq - beginSeq);

    auto beginPrimes = std::chrono::high_resolution_clock::now();
    primeNumbers(maxLimit);
    auto endPrimes = std::chrono::high_resolution_clock::now();

    auto elapsedPrimes = std::chrono::duration_cast<std::chrono::nanoseconds>(endPrimes - beginPrimes);

    cout<<"Algoritmul pentru numerele prime din secventa a durat: "<<elapsedSeq.count()*1e-9 <<endl;

    cout<<"Algoritmul pentru generarea numerelor prime durat: "<< elapsedPrimes.count()*1e-9<<endl;
}

void randomNumbersForInput(){
    int minNumber = pow(2,10) - 1;
    int maxNumber = pow(2,20)- 1;

    srand(time(NULL));

    for(int i = 0;i<10;i++) {
        int random = minNumber + rand() % maxNumber;

        fout<<"===================="<<endl;
        fout<<"Generarea numarul: "<<i<<endl;
        fout<<"Am generat numarul: "<< random<<endl;

        printInfoAboutNumber(random);

        fout<<endl<<endl;

    }
    cout<<"Am terminat de generat numerele si informatiile lor " <<endl;
}

void printOptions(){
    string prompt1 = "Optiunile din meniu sunt: ";

    string options[] = { "1. Numerele prime gasite mai mici decat n. \n",
                         "2. Numerele prime gasite mai mici decat 2^32 - 1 (max int) \n",
                         "3. Frecventa numerelor gasite. \n",
                         "4. Verifica daca pentru toate numerele prime gasite mai mici decat n sunt prime. \n",
                         "5. Raportul dintre numarul de prime gasite mai mici decat n si numarul de executii(n). \n",
                         "6. Cate numere prime am gasit mai mici decat n din numarul total de numere prime (<n). \n",
                         "7. Probabilitatea ca numerele prime gasite sa fie prime \n",
                         "8. Timpul necesar pentru a genere secventa de numere prime si generarea de numere prime (mai mci decat n). \n",
                         "9. Pentru diferite valori ale lui n(random), outputul, freceventa si probabilitatea ca toate numere sa fie prime. \n",
                         "10. 0 - EXIT .\n"} ;

    cout<<prompt1<<endl;

    for(int i = 0;i<10;i++)
        cout<<options[i];

}
int main() {
    int x;
    init_numbers();

    int opt;
    do{
        printOptions();

        cout<<"Alege o optiune:"<<endl;
        cout<<"===================="<<endl;
        cout<<"Optiunea aleasa: = ";
        cin>>opt;

        switch(opt){
            case 1:
                cout<<"Ai ales optiunea" << opt <<endl;
                cout<<"Da o valoare pentru n= ";
                cin>>x;

                primeNumbersLessThanN(x);
                break;
            case 2:
                cout<<"Ai ales optiunea " << opt <<endl;
                maxIntPrimes();

                break;
            case 3:
                cout<<"Ai ales optiunea " << opt <<endl;

                cout<<"Da o valoare pentru n= ";
                cin>>x;

                freqNumbers(x);
                break;
            case 4:
                cout<<"Ai ales optiunea " << opt <<endl;

                cout<<"Da o valoare pentru n= ";
                cin>>x;

                outputIsPrime(x);
                break;
            case 5:
                cout<<"Ai ales optiunea " << opt <<endl;

                cout<<"Da o valoare pentru n= ";
                cin>>x;

                execRaport( x);
                break;
            case 6:
                cout<<"Ai ales optiunea " << opt <<endl;

                cout<<"Da o valoare pentru n= ";
                cin>>x;

                primeNumbers(x);
                break;
            case 7:
                cout<<"Ai ales optiunea " << opt <<endl;

                cout<<"Da o valoare pentru n= ";
                cin>>x;

                accuracy(x);
                break;
            case 8:
                cout<<"Ai ales optiunea " << opt <<endl;

                cout<<"Da o valoare pentru n= ";
                cin>>x;

                timeMaxedNumber(x);
                break;
            case 9:
                cout<<"Ai ales optiunea " << opt <<endl;

                randomNumbersForInput();
                break;
            case 10:
                cout<<"Ai inchis programul \n";
                break;
            default:
                cout<<"Ai ales o optiune invalida \n";
                break;
        }
    }while(opt);

    return 0;
}
