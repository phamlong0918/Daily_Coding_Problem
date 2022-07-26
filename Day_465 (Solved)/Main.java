/** Medium
 * This problem was asked by Google.

Given a set of distinct positive integers, find the largest subset such that every pair of elements in the subset (i, j) satisfies either i % j = 0 or j % i = 0.

For example, given the set [3, 5, 10, 20, 21], you should return [5, 10, 20]. Given [1, 3, 6, 24], return [1, 3, 6, 24].
 */

import java.util.ArrayList;
import java.util.Arrays;

public class Main {

    public static class Node {
        public Node next;
        public int value;
    }

    public static void printNode(Node head) {
        Node cursor = head;
        while(cursor != null) {
            System.out.print(cursor.value);
            System.out.print("->");
            cursor = cursor.next;
        }
        System.out.println("null");
    }

    public static Node toLinkedList(ArrayList<Integer> arr) {
        Node result = null;
        for(int i = 0; i < arr.size(); ++ i) {
            Node newNode = new Node();
            newNode.next = result;
            newNode.value = arr.get(i);
            result = newNode;
        }
        return result;
    }


    public static void main(String[] args) {
        Node input_1 = toLinkedList(new ArrayList<>(Arrays.asList(3, 5, 10, 20, 21)));
        Node input_2 = toLinkedList(new ArrayList<>(Arrays.asList(1)));
        Node input_3 = toLinkedList(new ArrayList<>(Arrays.asList(5, 3, 7, 6, 24, 20)));
        
        printNode(input_1);
        printNode(reverse(input_1));

        printNode(input_2);
        printNode(reverse(input_2));

        printNode(input_3);
        printNode(reverse(input_3));
    }

    public static Node reverse(Node head) {
        if(head == null) {
            return head;
        }
        
        Node result = null;
        Node cursor = head;
        while(cursor != null) {
            Node tmpNextNode = cursor.next;
            cursor.next = result;
            result = cursor;
            cursor = tmpNextNode; 
        }

        return result;
    }
}