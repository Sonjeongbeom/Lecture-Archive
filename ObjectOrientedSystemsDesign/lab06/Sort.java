package lab06;

public class Sort {

	public static void main(String[] args) {
		int[] arr1 = {7, 4, 5, 1, 3};
		int[] arr2 = {9, 2, 2, 5, 4, 3, 1, 6, 7, 3, 8, 0, 3};
		
		printArr(arr1);
		bubbleSort(arr1, arr1.length);
		System.out.println("simple bubble sort");
		printArr(arr1);
		System.out.println();
		printArr(arr2);
		bubbleSort(arr2, arr2.length);
		System.out.println("simple bubble sort");
		printArr(arr2);
	}
	
	public static void bubbleSort(int arr[], int n) {
		for (int i = 0; i < arr.length-1; i++) {
			for (int j = i+1; j < arr.length; j++) {
				if (arr[i] > arr[j]) {
					int tmp;
					tmp = arr[i];
					arr[i] = arr[j]; 
					arr[j] = tmp; 
				}
			}
		}
	}
	
	public static void printArr(int arr[]) {
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();

	}


}
