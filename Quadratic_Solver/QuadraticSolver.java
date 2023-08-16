// Abrar Fahad CS361
// Project Description: The program solves quadratic equations, represented in the form ax^2 + bx + c = 0. 
// The solutions are determined using both the standard method (using the discriminant) and an alternate method.


import java.util.Arrays;

public class QuadraticSolver {

    public static final float EPSILON = 1e-9f;

    // Solve the quadratic equation using the standard method
    public static ComplexNumber[] solveUsingStandardMethod(float a, float b, float c) {
        // Check if 'a' is almost zero
        if (Math.abs(a) < EPSILON) {
            // Further checks to distinguish between invalid equations and linear equations
            if (Math.abs(b) < EPSILON) {
                if (Math.abs(c) < EPSILON) {
                    System.out.println("Infinite solutions as the equation reduces to 0=0");
                } else {
                    System.out.println("No solutions as the equation reduces to 0=c");
                }
                return null;
            }
            System.out.println("This is a linear equation, not a quadratic equation.");
            return new ComplexNumber[]{new ComplexNumber(-c / b, 0)};
        }

        // Calculate the discriminant of the quadratic equation
        float discriminant = b * b - 4 * a * c;
        ComplexNumber[] roots = new ComplexNumber[2];

        // Conditions to determine real and complex roots
        if (Math.abs(discriminant) < EPSILON) {
            roots[0] = new ComplexNumber(-b / (2 * a), 0);
            roots[1] = roots[0];
        } else if (discriminant > 0) {
            roots[0] = new ComplexNumber((-b + (float) Math.sqrt(discriminant)) / (2 * a), 0);
            roots[1] = new ComplexNumber((-b - (float) Math.sqrt(discriminant)) / (2 * a), 0);
        } else {
            roots[0] = new ComplexNumber(-b / (2 * a), (float) Math.sqrt(-discriminant) / (2 * a));
            roots[1] = new ComplexNumber(-b / (2 * a), -(float) Math.sqrt(-discriminant) / (2 * a));
        }
        return roots;
    }

    // Solve the quadratic equation using an alternate method
    public static ComplexNumber[] solveUsingAlternateMethod(float a, float b, float c) {
        ComplexNumber root1, root2;

        // Check if 'a' is almost zero
        if (Math.abs(a) < EPSILON) {
            // Further checks to distinguish between invalid equations and linear equations
            if (Math.abs(b) < EPSILON) {
                if (Math.abs(c) < EPSILON) {
                    System.out.println("Infinite solutions as the equation reduces to 0=0");
                } else {
                    System.out.println("No solutions as the equation reduces to 0=c");
                }
                return null;
            }
            System.out.println("This is a linear equation, not a quadratic equation.");
            return new ComplexNumber[]{new ComplexNumber(-c / b, 0)};
        }

        // Calculate the discriminant of the quadratic equation
        float discriminant = b * b - 4 * a * c;

        // Conditions to determine real and complex roots using the alternate method
        if (Math.abs(discriminant) < EPSILON) {
            root1 = new ComplexNumber(-b / (2 * a), 0);
            root2 = root1;
        } else if (discriminant > 0) {
            root1 = new ComplexNumber(2 * c / (-b - (float) Math.sqrt(discriminant)), 0);
            root2 = new ComplexNumber(2 * c / (-b + (float) Math.sqrt(discriminant)), 0);
        } else {
            root1 = new ComplexNumber(-b / (2 * a), (float) Math.sqrt(-discriminant) / (2 * a));
            root2 = new ComplexNumber(-b / (2 * a), -(float) Math.sqrt(-discriminant) / (2 * a));
        }

        return new ComplexNumber[]{root1, root2};
    }

    // Compute the second root based on the given first root
    public static ComplexNumber solveSecondRoot(float a, float b, float c, ComplexNumber r1) {
        if (Math.abs(r1.real) < EPSILON) {
            System.out.println("Can't calculate second root as the first root is zero");
            return null;
        }
        // If the root is real or complex
        if (Math.abs(r1.imaginary) < EPSILON) {
            return new ComplexNumber(c / (a * r1.real), 0);
        } else {
            return new ComplexNumber(r1.real, -r1.imaginary);
        }
    }

    public static void main(String[] args) {
        // Test cases
        float[][] testCases = {
                {0, 0, 0},
                {0, 5, 6},
                {1, 6, 9},
                {1, 1, 1},
                {6e2f, 6e10f, 1e-10f},
                {1, 1000.001f, 1},
                {1e-5f, 2, 1}
        };

        for (float[] testCase : testCases) {
            System.out.println("Testing case: " + Arrays.toString(testCase));

            // Solve using standard method
            ComplexNumber[] roots = solveUsingStandardMethod(testCase[0], testCase[1], testCase[2]);
            if (roots == null) {
                System.out.println("This is not a valid equation");
            } else {
                System.out.println("Roots using standard method: " + Arrays.toString(roots));
                verifyRoots(testCase[0], testCase[1], testCase[2], roots);
            }

            // Solve using alternate method
            roots = solveUsingAlternateMethod(testCase[0], testCase[1], testCase[2]);
            if (roots == null) {
                System.out.println("This is not a valid equation");
            } else {
                System.out.println("Roots using alternate method: " + Arrays.toString(roots));
                verifyRoots(testCase[0], testCase[1], testCase[2], roots);
            }

            // Solve the second root using the given first root
            if (roots != null && roots.length > 0) {
                ComplexNumber secondRoot = solveSecondRoot(testCase[0], testCase[1], testCase[2], roots[0]);
                System.out.println("Second root using given first root: " + secondRoot);
                verifySecondRoot(testCase[0], testCase[1], testCase[2], secondRoot);
            }

            System.out.println("-----------------------");
        }
    }

    // Verification of the roots
    public static void verifyRoots(float a, float b, float c, ComplexNumber[] roots) {
        for (ComplexNumber root : roots) {
            if (root != null) {
                // Taking into account both the real and imaginary parts for verification
                float resultReal = a * (root.real * root.real - root.imaginary * root.imaginary) + b * root.real + c;
                float resultImaginary = 2 * a * root.real * root.imaginary + b * root.imaginary;

                // Check if the result is almost zero
                if (areClose(resultReal, 0) && areClose(resultImaginary, 0)) {
                    System.out.println(root + " is a valid root.");
                } else {
                    System.out.println(root + " is NOT a valid root.");
                }
            }
        }
    }

    public static void verifySecondRoot(float a, float b, float c, ComplexNumber secondRoot) {
        // Check if secondRoot is null before using it.
        if(secondRoot == null) {
            System.out.println("Second root is null and cannot be verified.");
            return;
        }

        // Taking into account both the real and imaginary parts for verification
        float resultReal = a * (secondRoot.real * secondRoot.real - secondRoot.imaginary * secondRoot.imaginary) + b * secondRoot.real + c;
        float resultImaginary = 2 * a * secondRoot.real * secondRoot.imaginary + b * secondRoot.imaginary;

        // Check if the result is almost zero
        if (areClose(resultReal, 0) && areClose(resultImaginary, 0)) {
            System.out.println("The calculated root is valid.");
        } else {
            System.out.println("The calculated root is NOT valid.");
        }
    }
    public static boolean isAlmostZero(float value) {
        return Math.abs(value) <= .01;
    }

    public static boolean areClose(float a, float b) {
        if (isAlmostZero(a) && isAlmostZero(b)) return true;
        return Math.abs(a - b) / Math.max(Math.abs(a), Math.abs(b)) <= 0.01;
    }

}

class ComplexNumber {
    public float real;
    public float imaginary;

    public ComplexNumber(float real, float imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    // Converts the complex number to a string
    @Override
    public String toString() {
        if (Math.abs(imaginary) < QuadraticSolver.EPSILON) {
            return Float.toString(real);
        } else if (imaginary < 0) {
            return real + " - " + (-imaginary) + "i";
        } else {
            return real + " + " + imaginary + "i";
        }
    }
}