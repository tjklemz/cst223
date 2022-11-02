fn main() {
  let nums = vec![0, 2, 4, 5, 6, 7];

  let nums2: Vec<i32> = nums.into_iter().map(|x| x + 1).filter(|x| x % 2 == 0).collect();

  println!("{:?}", nums2);
}
