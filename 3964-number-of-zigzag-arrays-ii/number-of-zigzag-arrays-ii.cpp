class Solution {
public:
    static constexpr int M = 1000000007;
    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int size = A.size();
        Matrix C(size, vector<long long>(size, 0));
        for(int i = 0; i < size; i++) {
            for(int k = 0; k < size; k++) {
                if (A[i][k] == 0) continue; 
                for(int j = 0; j < size; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix A, int p) {
        int size = A.size();
        Matrix res(size, vector<long long>(size, 0));
        for(int i = 0; i < size; i++) res[i][i] = 1;
        
        while(p > 0) {
            if(p & 1) res = multiply(res, A);
            A = multiply(A, A);
            p >>= 1;
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int K = r - l + 1;
        int S = 2 * K;
        Matrix T(S, vector<long long>(S, 0));

        for(int x = 0; x < K; x++) {
            for(int y = 0; y < x; y++) {
                T[x + K][y] = 1; 
            }
            
            for(int y = x + 1; y < K; y++) {
                T[x][y + K] = 1; 
            }
        }

        Matrix Tn = power(T, n - 1);

        long long ans = 0;
        

        for(int i = 0; i < S; i++) {
            for(int j = 0; j < S; j++) {
                ans = (ans + Tn[i][j]) % M;
            }
        }

        return ans;
    }
};