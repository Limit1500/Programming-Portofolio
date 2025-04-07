    if (a[0] == '0')
        {
            for (int i = 1; i < n; i++)
            {
                permutare[0] = a[i];
                luate[i] = true;
                backtraking(1);
                luate[i] = false;
            }
        }
        else