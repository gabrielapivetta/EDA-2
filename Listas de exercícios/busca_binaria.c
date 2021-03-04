// Esta função recebe um inteiro x
// e um vetor crescente v[0..n-1]
// e devolve um índice j em 0..n 
// tal que v[j-1] < x <= v[j].

int buscaBinaria (int x, int n, int v[]) { 
   int e = -1, d = n;
   while (e < d-1) {  
      int m = (e + d)/2;
      if (v[m] < x) e = m;
      else d = m; 
   }
   return d;
}
