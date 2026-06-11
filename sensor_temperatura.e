class
    SENSOR_TEMPERATURA

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