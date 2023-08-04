/**
    * Abrar Fahad
    * Student ID:*******
    * CSCI 361
    * Project 2
    * IntegralCalculator is a Java class that provides methods to calculate integrals of given functions using different numerical techniques.
    * The class includes methods to calculate integrals using the Random Number Method, Midpoint Rule, Trapezoid Rule, and Simpson's Rule.
 */
import java.util.function.DoubleUnaryOperator;

public class IntegralCalculator {

    // Constants
    private static final double E = Math.E;
    private static final int[] ITERATIONS = {10000, 100000, 1000000};
    private static final double[] DX_VALUES = {0.5, 0.1};


    public static void main(String[] args) {
        System.out.println("Using Random Number Method:");
        calculateWithRandomNumber();

        System.out.println("\nUsing Midpoint Rule:");
        calculateWithMidpoint();

        System.out.println("\nUsing Trapezoid Rule:");
        calculateWithTrapezoid();

        System.out.println("\nUsing Simpson’s Rule:");
        calculateWithSimpsons();
    }

    // Method to print the result of each calculation along with the percentage error
    private static void printResultWithPercentage(String method, double calculated, double actual) {
        double error = calculateError(actual, calculated);
        System.out.printf("%s = %.8f -------------- Percentage error (%.2f%%)\n", method, calculated, error);
    }

    // Method to calculate the percentage error between the actual and calculated values
    private static double calculateError(double actual, double calculated) {
        return Math.abs((calculated - actual) / actual) * 100;
    }

    // Method to calculate integrals using the Random Number Method for different iterations and functions
    private static void calculateWithRandomNumber() {
        for (int iter : ITERATIONS) {
            System.out.println("\nFor " + iter + " iterations:");
            printResultWithPercentage("f1", randomMethod(0, 1, iter, IntegralCalculator::f1, 0, 4), Math.PI);
            printResultWithPercentage("f2", randomMethod(2, 5, iter, IntegralCalculator::f2, 0, 16), 34.5);
            printResultWithPercentage("f3", randomMethod(1, 4, iter, IntegralCalculator::f3, 0, 84), 108);
            printResultWithPercentage("f4", randomMethod(E, E + 1, iter, IntegralCalculator::f4, 0, 1 / Math.E), 0.2725138805);
        }
    }

    // Method to calculate integrals using the Midpoint Rule for different dx values and functions
    private static void calculateWithMidpoint() {
        for (double dx : DX_VALUES) {
            System.out.println("\nFor dx = " + dx + ":");
            printResultWithPercentage("f1", compositeMidpointRule(0, 1, dx, IntegralCalculator::f1), Math.PI);
            printResultWithPercentage("f2", compositeMidpointRule(2, 5, dx, IntegralCalculator::f2), 34.5);
            printResultWithPercentage("f3", compositeMidpointRule(1, 4, dx, IntegralCalculator::f3), 108);
            printResultWithPercentage("f4", compositeMidpointRule(E, E + 1, dx, IntegralCalculator::f4), 0.2725138805);
        }
    }

    // Method to calculate integrals using the Trapezoid Rule for different dx values and functions
    private static void calculateWithTrapezoid() {
        for (double dx : DX_VALUES) {
            System.out.println("\nFor dx = " + dx + ":");
            printResultWithPercentage("f1", compositeTrapezoidRule(0, 1, dx, IntegralCalculator::f1), Math.PI);
            printResultWithPercentage("f2", compositeTrapezoidRule(2, 5, dx, IntegralCalculator::f2), 34.5);
            printResultWithPercentage("f3", compositeTrapezoidRule(1, 4, dx, IntegralCalculator::f3), 108);
            printResultWithPercentage("f4", compositeTrapezoidRule(E, E + 1, dx, IntegralCalculator::f4), 0.2725138805);
        }
    }

    // Method to calculate integrals using Simpson's Rule for different dx values and functions
    private static void calculateWithSimpsons() {
        for (double dx : DX_VALUES) {
            System.out.println("\nFor dx = " + dx + ":");
            printResultWithPercentage("f1", compositeSimpsonsRule(0, 1, dx, IntegralCalculator::f1), Math.PI);
            printResultWithPercentage("f2", compositeSimpsonsRule(2, 5, dx, IntegralCalculator::f2), 34.5);
            printResultWithPercentage("f3", compositeSimpsonsRule(1, 4, dx, IntegralCalculator::f3), 108);
            printResultWithPercentage("f4", compositeSimpsonsRule(E, E + 1, dx, IntegralCalculator::f4), 0.2725138805);
        }
    }

    // Method to calculate integral using the Random Number Method with a given number of iterations and a function
    private static double randomMethod(double a, double b, int iterations, Function f, double min, double max) {
        int count = 0;
        for (int i = 0; i < iterations; i++) {
            double x = a + Math.random() * (b - a);
            double y = min + Math.random() * (max - min);
            if (y <= f.evaluate(x)) {
                count++;
            }
        }
        return (b - a) * (max - min) * count / iterations;
    }

    // Method to calculate integral using the Midpoint Rule with a given dx value and a function
    private static double compositeMidpointRule(double a, double b, double dx, DoubleUnaryOperator f) {
        double result = 0.0;
        int numberOfIntervals = (int)((b - a) / dx);
        double x = a;

        for (int i = 0; i < numberOfIntervals; i++) {
            double x1 = roundToDecimalPlaces(x, 4);
            double x2 = roundToDecimalPlaces(x + dx, 4);
            result += midpointRule(x1, x2, f::applyAsDouble);
            x += dx;
        }
        return result;
    }
    // Method to calculate the midpoint rule for a given range and function
    private static double midpointRule(double a, double b, Function f) {
        double midpoint = (a + b) / 2.0;
        return (b - a) * f.evaluate(midpoint);
    }
    // Method to calculate integral using the Trapezoid Rule with a given dx value and a function
    private static double compositeTrapezoidRule(double a, double b, double dx, DoubleUnaryOperator f) {
        double result = 0.0;

        int numberOfIntervals = (int)((b - a) / dx);
        double x = a;

        for (int i = 0; i < numberOfIntervals; i++) {
            double x1 = roundToDecimalPlaces(x, 4);
            double x2 = roundToDecimalPlaces(x + dx, 4);
            result += trapezoidRule(x1, x2, f::applyAsDouble);
            x += dx;
        }
        return result;
    }
    // Method to calculate the trapezoid rule for a given range and function
    private static double trapezoidRule(double a, double b, Function f) {
        double h = b - a;
        return 0.5 * h * (f.evaluate(a) + f.evaluate(b));
    }

    // Method to calculate integral using Simpson's Rule with a given dx value and a function
    private static double compositeSimpsonsRule(double a, double b, double dx, DoubleUnaryOperator f) {
        double result = 0.0;
        int numberOfIntervals = (int)((b - a) / dx);
        double x = a;

        for (int i = 0; i < numberOfIntervals; i++) {
            double x1 = roundToDecimalPlaces(x, 4);
            double x2 = roundToDecimalPlaces(x + dx, 4);
            result += simpsonsRule(x1, x2, f::applyAsDouble);
            x += dx;
        }
        return result;
    }
    // Method to calculate Simpson's rule for a given range and function
    private static double simpsonsRule(double a, double b, Function f) {
        double h = (b - a) / 2.0;
        double x1 = (a + b) /2.0;
        return (h / 3.0) * (f.evaluate(a) + 4 * f.evaluate(x1) + f.evaluate(b));
    }
    private static double roundToDecimalPlaces(double value, int places) {
        double scale = Math.pow(10, places);
        return Math.round(value * scale) / scale;
    }

    // Functions to be integrated
    private static double f1(double x) {
        return 4.0 / (1 + (x * x));
    }

    private static double f2(double x) {
        return 3 * x + 1;
    }

    private static double f3(double x) {
        return 5 * x * x + 2 * x - 4;
    }

    private static double f4(double x) {
        if (x == 0.0) return 0.0;
        return 1.0 / (x * Math.log(x));
    }

    // Functional interface to represent functions that can be integrated
    @FunctionalInterface
    interface Function {
        double evaluate(double x);
    }
}
