class
    APPLICATION

create
    make

feature

    make
        local
            estufa: ESTUFA
            opcao: INTEGER
            valor: REAL
        do
            create estufa.make ("Minha Estufa")

            from
                opcao := -1
            until
                opcao = 0
            loop
                print ("%N===== ESTUFA =====%N")
                print ("1 - Definir temperatura%N")
                print ("2 - Definir umidade%N")
                print ("3 - Monitorar estufa%N")
                print ("4 - Mostrar status%N")
                print ("0 - Sair%N")
                print ("opcao: ")

                io.read_integer
                opcao := io.last_integer

                inspect opcao
                when 1 then
                    print ("Temperatura: ")
                    io.read_real
                    valor := io.last_real

                    estufa.sensor_temperatura.set_valor (valor)

                when 2 then
                    print ("Umidade: ")
                    io.read_real
                    valor := io.last_real

                    estufa.sensor_umidade.set_valor (valor)

                when 3 then
                    estufa.monitorar

                when 4 then 
                    estufa.mostrar_status

                when 0 then
                    print ("Encerrando...%N")

                else
                    print ("Opcao invalida!%N")

                end
            end
        end
end