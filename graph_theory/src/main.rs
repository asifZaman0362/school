use std::io::stdin;

mod havel_hakimi;


fn main() -> std::io::Result<()> {
    let mut buf = String::new();
    loop {
        stdin().read_line(&mut buf)?;
        if buf.trim() == "exit" {
            break;
        }
        match havel_hakimi::has_simple_repr(&buf) {
            Ok(res) => {
                if res {
                    println!("Has simple representation");
                } else {
                    println!("Does not have simple representation");
                }
            }
            Err(err) => println!("Invalid invalid! {err}"),
        }
        buf.clear();
    }
    Ok(())
}
