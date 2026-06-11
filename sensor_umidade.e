class
    SENSOR_UMIDADE

inherit
    SENSOR
        redefine
            ler_valor
        end

create
    make

feature
    ler_valor: REAL
        do 
            Result := Precursor
        end
end