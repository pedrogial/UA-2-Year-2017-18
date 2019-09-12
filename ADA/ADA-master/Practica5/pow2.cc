#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

unsigned long calls_pow2_1;
unsigned long calls_pow2_2;
unsigned long calls_pow2_3;
unsigned long calls_pow2_4;

unsigned long pow2_1(unsigned n){
    unsigned long coste;
    calls_pow2_1++;

    if(n == 0){  
        coste = 1;
    } 
    else{
        if(n > 0){
            coste = 2 * pow2_1(n - 1);
        }
    }

  return(coste);
}

unsigned long pow2_2(unsigned n){
    unsigned long coste;
    calls_pow2_2++;

    if(n == 0){
        coste = 1;
    }
    else{
        if(n % 2 == 0){
            coste = pow2_2(n/2) * pow2_2(n/2);
        }
        else{ 
            if(n % 2 != 0){
                coste = 2 * pow2_2(n/2) * pow2_2(n/2);
            }
        }
    }
    return(coste);
}

unsigned long pow2_3(unsigned n){
    unsigned long coste, r;
    calls_pow2_3++;

    if(n == 0){
        coste = 1;
    }
    else{
        if(n % 2 == 0){
            r =  pow2_3(n/2);
            coste = r * r;
        }
        else{
            if(n % 2 != 0){
                r = pow2_3(n/2);
                coste = 2 * r * r;
            }
        }
    }
    return(coste);
}

unsigned long pow2_4(unsigned n){
    unsigned long coste;
    calls_pow2_4++;

    if(n == 0){
        coste = 1;
    }
    else{
        if(n > 0){
            coste = pow2_4(n - 1) + pow2_4(n - 1);
        }
  }
  return(coste);
}

int main(void){
    unsigned long bien;
    unsigned long coste;
    cout << std::fixed << setprecision(3);

    cout << setw(5) << "n" << std::flush;
    cout << setw(13) << "pow2_1" << std::flush;
    cout << setw(10) << "pow2_2" << std::flush;
    cout << setw(10) << "pow2_3" << std::flush;
    cout << setw(10) << "pow2_4" << std::flush;
    cout << endl;
    cout << "-------------------------------------------------" << endl; 

    for (unsigned i=0; i<= 500; i+=2){
        
        bien = powl(2,i);
        cout << setw(5) << i << std::flush;
    
        calls_pow2_1 = 0;
        calls_pow2_2 = 0;
        calls_pow2_3 = 0;
        calls_pow2_4 = 0;

        coste = pow2_1(i);
        if (coste != bien){
            cout << "Error de Coste en pow2_1"; 
            exit(1);
        }

        coste = pow2_2(i);
        if (coste != bien){
            cout << "Error de Coste en pow2_2";
            exit(1);
        }

        coste = pow2_3(i);
        if (coste != bien){
            cout << "Error de Coste en pow2_3";
            exit(1);
        }

        if (i <= 20){	
            coste = pow2_4(i);
            if (coste != bien){
                cout << "Error de Coste en pow2_4";
                exit(1);
            }
        }

        cout << setw(10) << calls_pow2_1 << std::flush; 
        cout << setw(10) << calls_pow2_2 << std::flush; 
        cout << setw(10) << calls_pow2_3 << std::flush;
        
        if(i <= 20){
            cout << setw(10) << calls_pow2_4 << std::flush;
        }
        cout << endl;
    }
}