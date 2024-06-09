namespace DP {

    int balancedBTs(int h) {
        if (h <= 1) {
            return 1;
        }


        int a = balancedBTs(h - 1);
        int b = balancedBTs(h - 2);

        int mod = 1e9 + 7;

        int x = ((long long) a * a) % mod;
        int y = (2 * (long long) a * b) % mod;

        return (x + y) % mod;
    }

    int balancedBTs_top_down(int h, int *arr) {
        if (h <= 1) {
            return 1;
        }
        if (arr[h] != -1) {
            return arr[h];
        }

        int a = balancedBTs_top_down(h - 1, arr);
        int b = balancedBTs_top_down(h - 2, arr);

        int mod = 1e9 + 7;

        int x = ((long long) a * a) % mod;
        int y = (2 * (long long) a * b) % mod;

        arr[h] = (x + y) % mod;

        return arr[h];
    }

    int balancedBTs_top_down(int h) {
        int *arr = new int[h + 1];

        for (int i = 0; i <= h; i++) {
            arr[i] = -1;
        }

        int output = balancedBTs_top_down(h, arr);

        delete [] arr;

        return output;
    }

    int balancedBTs_bottom_up(int h) {
        if (h <= 1) {
            return 1;
        }
        int *ans = new int[h + 1];
        ans[0] = 1;
        ans[1] = 1;
        int mod = 1e9 + 7;

        for (int i = 2; i <= h; i++) {
            int temp1 = ((long long)(ans[i - 1]) * ans[i - 1]) % mod;
            int temp2 = (2 * (long long)(ans[i - 1]) * ans[i - 2]) % mod;

            ans[i] = (temp1 + temp2) % mod;
        }
        return ans[h];
    }
}