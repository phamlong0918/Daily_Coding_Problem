/** Hard
 * This problem was asked by Nvidia.

Find the maximum of two numbers without using any if-else statements, branching, or direct comparisons.
 */

public class Main {
    public static void main(String[] args) {
        System.out.println((maxOf(7, 8) == 8 ? "[Pass]" : "[Fail]") + ".Max is " + maxOf(7, 8));
        System.out.println((maxOf(8, 7) == 8 ? "[Pass]" : "[Fail]") + ".Max is " + maxOf(8, 7));
        System.out.println((maxOf(100, 2) == 100 ? "[Pass]" : "[Fail]") + ".Max is " + maxOf(100, 2));
        System.out.println((maxOf(2, 100) == 100 ? "[Pass]" : "[Fail]") + ".Max is " + maxOf(2, 100));
    }

    public static int maxOf(int a, int b) {
        return (a + b + Math.abs(a - b)) / 2;
    }
}