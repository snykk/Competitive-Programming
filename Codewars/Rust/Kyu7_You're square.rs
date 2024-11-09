fn is_square(n: i64) -> bool {
    let sqrt = (n as f64).sqrt();
    return if sqrt % 1.0 == 0.0 {true} else {false};
}