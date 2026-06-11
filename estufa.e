class ESTUFA

create

	make

feature
	nome: STRING

	sensor_temperatura: SENSOR_TEMPERATURA
	sensor_umidade: SENSOR_UMIDADE

	irrigacao: IRRIGACAO
	controlador: CONTROLADOR

	make (n: STRING)
		do 
			nome := n

			create sensor_temperatura.make
			create sensor_umidade.make

			create irrigacao.make
			create controlador.make
		
		end

	monitorar
		do
			controlador.controlar_umidade(
				sensor_umidade.ler_valor,
				irrigacao
			)

			controlador.verificar_temperatura (
				sensor_temperatura.ler_valor
			)
		end

	mostrar_status
		do
			print ("%N===== STATUS DA ESTUFA =====%N")

        print ("Temperatura: ")
        print (sensor_temperatura.ler_valor)
        print (" °C%N")

        print ("Umidade: ")
        print (sensor_umidade.ler_valor)
        print (" %% %N")

        if irrigacao.ligada then
            print ("Irrigacao: Ligada%N")
        else
            print ("Irrigacao: Desligada%N")
        end
	end
end
