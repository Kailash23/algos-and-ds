
    while (i < len1 && j < len2) {
        if (array1[i] > array2[j]) {
            sumArray1 += array1[i];
        } else if (array1[i] < array2[j]) {
            sumArray2 += array2[j];
        } else {
            sumArray1 += array1[i];
            sumArray2 += array2[j];
            totalMaxSum += max(sumArray1, sumArray2);
        };
    };