

/**
 * 给定一个数组，将其中的奇数都放在偶数后面，并且最后奇数部分和偶数部分都需要升序排列
 * 思路：将奇数和偶数分隔后分别进行快速排序
 */
public class Main {
    
    static void quickSort(int[] nums, int start, int end) {
        if (nums == null || start >= end - 1 || start < 0 || end > nums.length) {
            return ;
        }
        int left = start, right = end - 1;
        int t = nums[left];
        while (left < right) {
            while (left < right && nums[right] >= t) {
                right--;
            }
            nums[left] = nums[right];
            while (left < right && nums[left] <= t) {
                left++;
            }
            nums[right] = nums[left];
        }
        nums[left] = t;
        quickSort(nums, start, left);
        quickSort(nums, left + 1, end);
    }
    
    // 判断 n 是否是奇数
    static boolean isOdd(int n) {
        return (n & 1) == 1;
    }
    
    // 分隔，将 nums 数组中的奇数都放在偶数后面
    static int divide(int[] nums, int start, int end) {
        if (nums == null || start < 0 || end >= nums.length) {
            return -1;
        }
        while (start < end && isOdd(nums[end])) {
            end--;
        }
        int t = nums[end];
        while (start < end) {
            while (start < end && !isOdd(nums[start])) {
                start++;
            }
            nums[end] = nums[start];
            while (start < end && isOdd(nums[end])) {
                end--;
            }
            nums[start] = nums[end];
        }
        nums[end] = t;
        return start + (isOdd(nums[end]) ? 0 : 1);
    }
    
    static void display(int[] nums) {
        if (nums == null) {
            return ;
        }
        for (int i : nums) {
            System.out.print(i + " ");
        }
        System.out.println();
    }
    
    static void solve(int[] nums) {
        if (nums == null || nums.length <= 1) {
            return ;
        }
        int mid = divide(nums, 0, nums.length - 1);
        quickSort(nums, 0, mid);
        quickSort(nums, mid, nums.length);
        display(nums);
    }
    
    
    public static void main(String[] args) {
        int[] nums = {3, 1, 4, 5, 6, 11212211, 56544353, 66};
        solve(nums);
    }
}