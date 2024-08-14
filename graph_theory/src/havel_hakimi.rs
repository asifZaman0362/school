pub fn has_simple_repr(input: &str) -> Result<bool, core::num::ParseIntError> {
    Ok(reorder_remove_subtract(
        input
            .split(",")
            .map(|str| str.trim().parse::<i32>())
            .collect::<Result<Vec<_>, core::num::ParseIntError>>()?,
    ))
}

fn reorder_remove_subtract(mut deg_seq: Vec<i32>) -> bool {
    let mut early_return = true;
    for &i in &deg_seq {
        if i > 0 {
            early_return = false;
            break;
        } else if i < 0 {
            return false;
        }
    }
    if early_return {
        return true;
    } else {
        deg_seq.sort();
        let n = deg_seq
            .pop()
            .expect("Atleast one element is expected to be in the sequence at this point!")
            as usize;
        for item in &mut deg_seq[..n] {
            *item -= 1;
        }
        reorder_remove_subtract(deg_seq)
    }
}
