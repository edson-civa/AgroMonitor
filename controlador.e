class 
    CONTROLADOR

create
    make

feature

    make
        do
        end

    controlar_umidade (
        umidade: REAL;
        irrigacao: IRRIGACAO
    )
        do
            if umidade < 30.0 then
                irrigacao.ligar
                print ("Irrigacao Ligada%N")
            elseif umidade > 70.0 then
                irrigacao.desligar
                print ("Irrigacao desligada.%N")
            end
        end

        verificar_temperatura(temperatura: REAL)
            do
                if temperatura > 40.0 then
                    print ("ALERTA: Temperatura alta!%N")

            end
        end
end