use std::collections::HashMap;

type Table = HashMap<String, Vec<String>>;

fn show(artists: &Table) {
    for (artist, works) in artists {
        println!("works by {}:", artist);
        for work in works {
            println!("  {}", work);
        }
    }
}

fn sort_works(artists: &mut Table) {
    for (_, works) in artists {
        works.sort();
    }
}

fn main() {
    let mut artists = Table::new();    
    artists.insert("Gesualdo".to_string(),
                   vec!["many madrigals".to_string(), 
                        "Tenebrae Responsoria".to_string()]);
    artists.insert("Caravaggio".to_string(),
                   vec!["The Musicians".to_string(),
                        "The Calling of St. Matthew".to_string()]);
    artists.insert("Cellini".to_string(),
                   vec!["Perseus with the head of Medusa".to_string(),
                        "a salt cellar".to_string()]);
    sort_works(&mut artists);
    show(&artists);
}
