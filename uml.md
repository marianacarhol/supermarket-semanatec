classDiagram
    class Ingrediente {
        -string nom
        -float peso
        -int id
        -int cant
        +getNom() string
        +setNom(string) void
        +getPeso() float
        +setPeso(float) void
        +getId() int
        +setId(int) void
        +getCant() int
        +setCant(int) void
    }

    class Platillo {
        -string nom
        -string tipo
        -vector<Ingrediente> ingredientes
        -string receta
        +getNom() string
        +getTipo() string
        +getIngredientes() vector<Ingrediente>
        +getReceta() string
    }

    class Gastronomia {
        -string tipo
        +getTipo() string
    }

    class Inventario {
        +getCantidad(Ingrediente) int
        +setCantidad(Ingrediente, int) void
        +getNom(Ingrediente) string
    }

    class Menu {
        -string opcion1
        -string opcion2
        +print(string opcion1) void
        +print(string opcion2) void
    }

    Platillo --|> Gastronomia : herencia
    Platillo "1" --> "*" Ingrediente : contiene
