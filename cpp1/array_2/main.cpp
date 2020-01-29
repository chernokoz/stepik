#include <iostream>

using namespace std;

int ** transpose(const int * const * m, unsigned rows, unsigned cols) {
    int ** ans = new int * [cols];
    for (int k = 0; k < cols; ++k) {
        ans[k] = new int [rows];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            ans[j][i] = m[i][j];
        }
    }
    return ans;
}

int ** create_array2(size_t a, size_t b) {
    int ** m = new int * [a];
    for (int i = 0; i < a; ++i) {
        m[i] = new int [b];
    }
    return m;
}

void print_array2(int ** m, size_t a, size_t b) {
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void free_array2(int ** m, size_t a, size_t b) {
    for (int i = 0; i < a; ++i) {
        delete [] m[i];
    }
    delete [] m;
}

void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int min = m[0][0];
    int coll_of_min = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (m[i][j] < min) {
                min = m[i][j];
                coll_of_min = i;
            }
        }

    }
    int * tmp = m[0];
    m[0] = m[coll_of_min];
    m[coll_of_min] = tmp;
}


int main() {
    int ** m = create_array2(3, 4);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            m[i][j] = - (i + 1) * (j + 1);
        }
    }
    print_array2(m, 3, 4);
    int ** m1 = transpose(m, 3, 4);
    print_array2(m1, 4, 3);
    free_array2(m1, 4, 3);
    swap_min(m, 3, 4);
    print_array2(m, 3, 4);
    free_array2(m, 3, 4);
    return 0;
}
