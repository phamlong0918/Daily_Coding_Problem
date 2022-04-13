/** Medium
 * This problem was asked by Google.

Given a set of distinct positive integers, find the largest subset such that every pair of elements in the subset (i, j) satisfies either i % j = 0 or j % i = 0.

For example, given the set [3, 5, 10, 20, 21], you should return [5, 10, 20]. Given [1, 3, 6, 24], return [1, 3, 6, 24].
 */

import java.util.List;
import java.util.Map;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        ArrayList<Integer> input_1 = new ArrayList<>(Arrays.asList(3, 5, 10, 20, 21));
        ArrayList<Integer> input_2 = new ArrayList<>(Arrays.asList(1, 3, 6, 24));
        ArrayList<Integer> input_3 = new ArrayList<>(Arrays.asList(5, 3, 7, 6, 24, 20));

        System.out.println(largetSubset_1(input_1));
        System.out.println(largetSubset_1(input_2));
        System.out.println(largetSubset_1(input_3));

        System.out.println(largetSubset_2(input_1));
        System.out.println(largetSubset_2(input_2));
        System.out.println(largetSubset_2(input_3));
    }

    // Solution 1: Sort: Onlog n + find number with the most multiple: On2
    public static ArrayList<Integer> largetSubset_1(ArrayList<Integer> arr) {
        if(arr.size() <= 1) {
            return arr;
        }
        
        Collections.sort(arr);
        int numberWithMostMultiple = arr.get(0);
        int mostMultiple = 0;
        for(int i = 0; i < arr.size()-1; ++ i) {
            int multipleOfArrI = 1;
            for(int j = i + 1; j < arr.size(); ++ j) {
                if(arr.get(j) % arr.get(i) == 0) {
                    multipleOfArrI += 1;
                }
            }
            if(multipleOfArrI > mostMultiple) {
                mostMultiple = multipleOfArrI;
                numberWithMostMultiple = arr.get(i);
            }
        }
        
        ArrayList<Integer> result = new ArrayList<>();
        for(int i = 0; i < arr.size(); ++ i) {
            if(arr.get(i) % numberWithMostMultiple == 0) {
                result.add(arr.get(i));
            }
        }
        return result;
    }

        // Solution 1: Sort: Onlog n + find number with the most multiple: On2
        public static ArrayList<Integer> largetSubset_2(ArrayList<Integer> arr) {
            if(arr.size() <= 1) {
                return arr;
            }
            
            Collections.sort(arr);
            Map<Integer, ArrayList<Integer>> resultMap =  new HashMap<>();

            for(int i = 0; i < arr.size(); ++ i) {
                boolean isFirstNumber = true;
                for(Map.Entry<Integer, ArrayList<Integer>> entry : resultMap.entrySet()) {
                    if(arr.get(i) % entry.getKey() == 0) {
                        isFirstNumber = false;
                        entry.getValue().add(arr.get(i));
                    }
                }

                if(isFirstNumber) {
                    resultMap.put(arr.get(i), new ArrayList<>(Arrays.asList(arr.get(i))));
                }
            }
            
            ArrayList<Integer> result = new ArrayList<>();
            for(Map.Entry<Integer, ArrayList<Integer>> entry : resultMap.entrySet()) {
                if(result.size() < entry.getValue().size()) {
                    result = entry.getValue();
                }
            }
            return result;
        }
}