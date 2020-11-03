import java.util.*;

public class Chaman {

    public static void main(String[] args) {
        int n, m, k;

        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        k = scanner.nextInt();

        RectangleWithPoints[] rectanglesWithPoints = new RectangleWithPoints[k];

        RectangleWithPoints rectangleWithPoints;

        SortedSet xys2 = new TreeSet();

        for (int i = 0; i < k; i++) {
            rectangleWithPoints = new RectangleWithPoints();
            rectangleWithPoints.x = scanner.nextInt();
            rectangleWithPoints.y = scanner.nextInt();
            rectangleWithPoints.z = scanner.nextInt();
            rectanglesWithPoints[i] = rectangleWithPoints;

            xys2.add(rectangleWithPoints.x);
            xys2.add(rectangleWithPoints.y);

        }



        Arrays.sort(rectanglesWithPoints, new Comparator<RectangleWithPoints>() {
            @Override
            public int compare(RectangleWithPoints o1, RectangleWithPoints o2) {
                return o1.x - o2.x;
            }
        });


        List<Integer> listNumbers = new ArrayList<Integer>( xys2);
        System.out.println(n * m - GetCoveredArea(rectanglesWithPoints, listNumbers, k));
    }

    static int GetCoveredArea(RectangleWithPoints[] rectangles, List<Integer> xys, int k) {
        int area = 0; // initial value

        int x1, x2;
        int j = 0;
        for (int i = 0; i < xys.size() - 1; i++) {
            x1 = xys.get(i);
            x2 = xys.get(i+1);

            if (x1 < x2) {
                RectangleWithEdges rwe = new RectangleWithEdges();
                rwe.horizontal = x2 - x1;
                rwe.vertical = 0;
                // If the range new rectangles edge is after the original rectangles, update counter
                while (rectangles[j].y < x1) {
                    j++;
                }
                for (int t = j; t < k; t++) {
                    if (rectangles[t].y >= x2 && rectangles[t].x <= x1) {
                        rwe.vertical = Math.max(rectangles[t].z, rwe.vertical);
                    }
                }

                area += rwe.vertical * rwe.horizontal;
            }

        }
        return area;
    }
}

class RectangleWithPoints {
    int x; // bottom left
    int y; // bottom right
    int z; // top left


};

class RectangleWithEdges {
    int horizontal;
    int vertical;
};