
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
        int filosofos = 5, colheres = 5,tempo = 10000, porcentagem = 1000, c0 = 0, comendo = 0;

        struct filosofo{
            float Tcomendo = 0;
            float Tpensando = 0;
            int porcentagemComendo = 0;
            int colherDisponivel = 1;
            //0 não pegou -1 pegou da esquerda e 1 pegou da direita
            int colherPega = 0;
            bool ok = false;
            bool morreu = false;
        };
        
        
    srand (time(NULL));
        struct  filosofo a,b,c,d,e;

    for (int i = 0; i < tempo; i++) {
        if(a.ok && a.Tcomendo == porcentagem){
            a.ok = false;
            colheres+=2;
        }
        if(b.ok && b.Tcomendo == porcentagem){
            b.ok = false;
            colheres+2;
        }
        if(c.ok && c.Tcomendo == porcentagem){
            c.ok = false;
            colheres+=2;
        }
        if(d.ok && d.Tcomendo == porcentagem){
            d.ok = false;
            colheres+=2;
        }
        if(e.ok && e.Tcomendo == porcentagem){
            e.ok = false;
            colheres+=2;
        }
        if(colheres >= 2) {
            c0 = rand() % 5 + 1;
            if (c0 == 1) {
                a.ok = true;
                colheres = colheres -2;
            }
            else if(c0 == 2){
                b.ok = true;
                colheres = colheres -2;
            }
            else if(c0 == 3){
                c.ok = true;
                colheres = colheres -2;
            }
            else if(c0 == 4){
                d.ok = true;
                colheres = colheres -2;
            }
            else if(c0 == 5){
                e.ok = true;
                colheres = colheres -2;
            }
        }
        if(!a.ok) {
            a.Tpensando++;
        }
        if(!b.ok){
            b.Tpensando++;
        }
        if(!c.ok){
            c.Tpensando++;
        }
        if(!d.ok){
            d.Tpensando++;
        }
        if(!e.ok){
            e.Tpensando++;
        }
    }
        /*
    for (int i = 0; i < tempo; i++) {
        c0 = rand() % 5 + 1;
        // true == comendo;
        if(comendo < 2) {
            if ((c0 == 1 && a.ok) && (b.colherDisponivel != 0 || e.colherDisponivel != 0)) {
                a.ok = false;
                a.colherDisponivel = 0;
                comendo++;
                if (b.colherDisponivel != 0) {
                    b.colherDisponivel = 0;
                    a.colherPega = 1;
                } else {
                    e.colherDisponivel = 0;
                    a.colherPega = -1;
                }
            } else if (c0 == 1 && !a.ok) {
                a.ok = true;
                a.colherDisponivel = 1;
                
                if (a.colherPega == 1) {
                    b.colherDisponivel = 1;
                } else {
                    e.colherDisponivel = 1;
                }
                a.colherPega = 0;
            } else if ((c0 == 2 && b.ok) && (c.colherDisponivel != 0 || a.colherDisponivel != 0)) {
                b.ok = false;
                b.colherDisponivel = 0;
                comendo++;
                if (a.colherDisponivel != 0) {
                    a.colherDisponivel = 0;
                    b.colherPega = -1;
                } else {
                    c.colherDisponivel = 0;
                    b.colherPega = 1;
                }
            } else if (c0 == 2 && !b.ok) {
                b.ok = true;
                b.colherDisponivel = 1;
                
                if (b.colherPega == -1) {
                    a.colherDisponivel = 1;
                } else {
                    c.colherDisponivel = 1;
                }
                b.colherPega = 0;
            } else if ((c0 == 3 && c.ok) && (d.colherDisponivel != 0 || b.colherDisponivel != 0)) {
                c.ok = false;
                c.colherDisponivel = 0;
                comendo++;
                if (d.colherDisponivel != 0) {
                    d.colherDisponivel = 0;
                    c.colherPega = 1;
                } else {
                    b.colherDisponivel = 0;
                    c.colherPega = -1;
                }
            } else if (c0 == 3 && !c.ok) {
                c.ok = true;
                c.colherDisponivel = 1;
                
                if (c.colherPega == -1) {
                    b.colherDisponivel = 1;
                } else {
                    d.colherDisponivel = 1;
                }
                c.colherPega = 0;
            } else if ((c0 == 4 && d.ok) && (c.colherDisponivel != 0 || e.colherDisponivel != 0)) {
                d.ok = false;
                d.colherDisponivel = 0;
                comendo++;
                if (c.colherDisponivel != 0) {
                    c.colherDisponivel = 0;
                    d.colherPega = -1;
                } else {
                    e.colherDisponivel = 0;
                    d.colherPega = 1;
                }
            } else if (c0 == 4 && !d.ok) {
                d.ok = true;
                d.colherDisponivel = 1;
                
                if (d.colherPega == 1) {
                    e.colherDisponivel = 1;
                } else {
                    c.colherDisponivel = 1;
                }
                d.colherPega = 0;
            } else if ((c0 == 5 && e.ok) && (a.colherDisponivel != 0 || d.colherDisponivel != 0)) {
                e.ok = false;
                e.colherDisponivel = 0;
                comendo++;
                if (a.colherDisponivel != 0) {
                    a.colherDisponivel = 0;
                    e.colherPega = 1;
                } else {
                    d.colherDisponivel = 0;
                    e.colherPega = -1;
                }
            } else if (c0 == 5 && !e.ok) {
                e.ok = true;
                e.colherDisponivel = 1;
                
                if (e.colherPega = -1) {
                    d.colherDisponivel = 1;
                } else {
                    a.colherDisponivel = 1;
                }
                d.colherPega = 0;
            }
        }
        
        else{
            if(!a.ok){
                a.Tcomendo++;
            }
            if(a.Tcomendo >= porcentagem){
                comendo--;
                a.Tcomendo = 0;
            }
            if(!b.ok){
                b.Tcomendo++;
            }
            if(b.Tcomendo >= porcentagem){
                comendo--;
                b.Tcomendo = 0;
            }
            if(!c.ok){
                c.Tcomendo++;
            }
            if(c.Tcomendo >= porcentagem){
                comendo--;
                c.Tcomendo = 0;
            }
            if(!d.ok){
                d.Tcomendo++;
            }
            if(d.Tcomendo >= porcentagem){
                comendo--;
                d.Tcomendo = 0;
            }
            if(!e.ok){
                e.Tcomendo++;
            }
            if(e.Tcomendo >= porcentagem){
                comendo--;
                e.Tcomendo = 0;
            }
        }
        if(a.ok){
            a.Tpensando++;
        }
        else{
            a.Tcomendo++;
        }
        if(b.ok){
            b.Tpensando++;
        }
        else {
            b.Tcomendo++;
        }
        if(c.ok){
            c.Tpensando++;
        }
        else{
            c.Tcomendo++;
        }
        if(d.ok){
            d.Tpensando++;
        }
        else{
            d.Tcomendo++;
        }
        if(e.ok){
            e.Tpensando++;
        }
        else{
            e.Tcomendo++;
        }
    }
*/
    printf("A = %f\n"
           "B = %f\n"
           "C = %f\n"
           "D = %f\n"
           "E = %f\n",a.Tcomendo,b.Tcomendo,c.Tcomendo,
           d.Tcomendo,e.Tcomendo);
puts("");
    printf("A = %f\n"
           "B = %f\n"
           "C = %f\n"
           "D = %f\n"
           "E = %f\n",a. Tpensando,b. Tpensando,c. Tpensando,
           d. Tpensando,e. Tpensando);
    puts("");
    printf("A = %f\n"
           "B = %f\n"
           "C = %f\n"
           "D = %f\n"
           "E = %f\n",(a.Tcomendo/a.Tpensando),(b.Tcomendo/b.Tpensando),(c.Tcomendo/c.Tpensando),
           (d. Tpensando/d.Tpensando),(e.Tcomendo/e.Tpensando));
    return 0;
}