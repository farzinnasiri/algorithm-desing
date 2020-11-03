import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class KingsParty {

    static List<int[]> allInvitedCommandersCombinations;
    static int result = 0;
    static int total = 0;
    static int[][] conflicts;

    public static void main(String[] args) {
        int n, k, m;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        k = scanner.nextInt();
        m = scanner.nextInt();

        int[] commanders = new int[n];
        for (int i = 0; i < n; i++) {
            commanders[i] = i + 1;
        }

        conflicts = new int[m][2];

        for (int i = 0; i < m; i++) {
            conflicts[i][0] = scanner.nextInt();
            conflicts[i][1] = scanner.nextInt();
        }

        allInvitedCommandersCombinations = new ArrayList<>();

        int[] invitedCommanders = new int[k];
        findCombination(commanders, invitedCommanders, 0, n - 1, 0, k);


        int res = 0;
        for (int i = 0; i < allInvitedCommandersCombinations.size(); i++) {
            for (int s = 0; s < m; s++) {
                if (isSubset(allInvitedCommandersCombinations.get(i), conflicts[s], k, 2)) {
                    res++;
                    break;
                }
            }
        }
        System.out.println(total-result);

    }

    // check if arr2 is subset of arr1
    static boolean isSubset(int arr1[],
                            int arr2[], int m, int n) {
        int i = 0;
        int j = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++)
                if (arr2[i] == arr1[j])
                    break;

            if (j == m)
                return false;
        }
        return true;
    }

    static void findCombination(int[] arr, int[] invitedCommanders, int start, int end, int index, int k) {
        // Stop if seats got full
        if (index == k) {
            checkConflict(invitedCommanders,k);
            return;
        }
        for (int i = start; i <= end && end - i + 1 >= k - index; i++) {
            invitedCommanders[index] = arr[i];
            findCombination(arr, invitedCommanders, i + 1,
                    end, index + 1, k);
        }
    }
    // deleted conflicted combinations
    static void checkConflict(int[] invitedCommanders,int k) {
        total++;
        for (int s = 0; s < conflicts.length; s++) {
            if (isSubset(invitedCommanders, conflicts[s], k, 2)) {
                result++;
                break;
            }
        }
    }
}
