#include <iostream>
#include <string>

using namespace std;

int aRes[100][100];
int aEntrada[102][102];

int resposta;
  
void initArr();
void imprimir(string nome, int R, int C);
void initSentinela(int, int);
int testaMatrixResolucao();
void resolveMatrix (int  i, int j);

int main(void) {
    
    int N, R, C;
    string nome;
    
    cin >> N;
    
    for (int i=0; i<N; i++) {
        initArr();
        resposta = 0;
        cin >> nome >> R >> C;
        
        initSentinela(R, C);
        
        for (int j=0; j<R; j++) {
            
            for (int k=0; k<C; k++) {
                cin >> aEntrada[j+1][k+1];
            }
        }
        
        for (int l = 1; l <= R; l++)
        {
            for (int ll = 1; ll <= C; ll++)
            {
                if (aRes[l][ll] == -1)
                {
                    resolveMatrix (l, ll);
                }
                
            }
        }
        cout << nome <<": " <<  resposta << endl;
        

    }
    
    return 0;
}

void imprimir(string nome, int R, int C) {
    
    cout << nome << endl;
    for (int i=1; i<=R; i++) {
        for (int j=1; j<=C; j++) {
            cout << aEntrada[i][j] << " ";
        }
        
        cout << endl;
    }
}

void initArr() {
     for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) { aRes[i][j] = -1;}
    }
}

void initSentinela(int R, int C) {
    for (int i=0; i<102; i++) {
        aEntrada[0][i] = aEntrada [i][0] = aEntrada[R+1][i] = aEntrada[i][C+1] = 101;
    }
} 

int testaMatrixResolucao()
{
    int max = -1;
     for (int i=0; i<100; i++) 
        for (int j=0; j<100; j++) 
            if (max < aRes[i][j])
                max = aRes[i][j];
    
    return max;
}


void resolveMatrix (int  i, int j)
{
    int maxim = 0;
   
    if (aRes[i][j] != -1)
        return;

    
    //teste 0
    if (aEntrada[i][j+1] < aEntrada[i][j])
    {
        //verifica se esta resolvido
        if (aRes[i][j+1] == -1)
        //se nao esta resolvido
        {
            resolveMatrix(i, j + 1);
        }
        if (aRes[i][j+1] > maxim)
            maxim = aRes[i][j+1]; 
    } 
    //teste 1
    if (aEntrada[i+1][j] < aEntrada[i][j])
    {
       //verifica se esta resolvido
        if (aRes[i+1][j] == -1)
        //se nao esta resolvido
        {
            resolveMatrix(i + 1, j);
        }   
        if (aRes[i+1][j] > maxim)
            maxim = aRes[i+1][j];
    }
    //teste 2
    if (aEntrada[i][j-1] < aEntrada[i][j])
    {
       //verifica se esta resolvido
        if (aRes[i][j-1] == -1)
        //se nao esta resolvido
        {
            resolveMatrix(i, j - 1);
        }  
        if (aRes[i][j-1] > maxim)
            maxim = aRes[i][j-1];
    }
    //teste 3
    if (aEntrada[i-1][j] < aEntrada[i][j])
    {
        //verifica se esta resolvido
        if (aRes[i-1][j] == -1)
        //se nao esta resolvido
        {
            resolveMatrix(i - 1, j);
        }   
        if (aRes[i-1][j] > maxim)
            maxim = aRes[i-1][j];
    }
   
  aRes[i][j] = ++maxim;
    
  if (maxim > resposta)
    resposta = maxim;
  
}