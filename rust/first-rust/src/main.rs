fn main() {
    println!("Hello, world!");

    for i in 0..10 {
        println!("No.{}", i);
    }

    let mut x: i32 = 5;
    x = x + 1;

    println!("The value of x is: {}", x);

    // let y: i32 = 5;
    // y = y + 1;

    // println!("The value of y is: {}", y);

    if x < 10 {
        println!("x is less than 10");
    } else {
        println!("x is greater than or equal to 10");
    }
}
