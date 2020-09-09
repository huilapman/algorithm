class Solution {
public:
    map<int, int> fib_no;
        
    int fib_bottom_up(int N) {
        if (N == 0) {
            return 0;
        }
        else if (N == 1) {
            return 1;
        }
        else {
            //0 1 2 3 4 5 6
            //0 1 1 2 3 5 8
            int a = 0;
            int b = 1;
            int c = 0;
            for (int i=2; i<= N; ++i) {
                c = a + b;
                a = b;
                b = c;
            }
            return c;
        }
    }
    
    int fib_top_down(int N) {
        if (N == 0) {
            return 0;
        }
        else if (N == 1) {
            return 1;
        }
        else  {
            if (fib_no.find(N-1) == fib_no.end()) {
                fib_no.insert(std::pair<int, int>(N-1, fib(N-1)));
            }
            if (fib_no.find(N-2) == fib_no.end()) {
                fib_no.insert(std::pair<int, int>(N-2, fib(N-2)));
            }
                              
            return fib_no[N-1] + fib_no[N-2];
        }
    }
    
    int fib(int N) {
        return fib_bottom_up(N);
    }
    
};
