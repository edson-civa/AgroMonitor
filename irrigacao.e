class
    IRRIGACAO

create
    make

feature
    ligada: BOOLEAN

    make    
        do
            ligada := False
        end
    
    ligar
        do
            ligada := True
        end
    
    desligar
        do
            ligada := False
        end
end