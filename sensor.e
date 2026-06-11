class
    SENSOR

create
    make

feature {NONE}
    valor: REAL

feature
    make
        do
            valor := 0.0
        end

    ler_valor: REAL
        do
            Result := valor
        end

    set_valor (v: REAL)
        do
            valor := v
        end
end