import sys
import re

def parse(input):

	medicoes = []
	teste = []
	with open(input, "r") as finput:
		for index, line in enumerate(finput):
			if index != 0:
				teste.append(line)
				if index % 3 == 0:
					medicoes.append(teste)
					teste = []
	return medicoes

def encontra_falsa(verdadeiras, falsas, medicoes):

	for medicao in medicoes:
		for teste in medicao:
			resultado = re.findall('[\w]+', teste)
			if resultado[2] == 'even':

				for moeda in resultado[0]+resultado[1]:
					verdadeiras.add(moeda)

			elif resultado[2] != 'even' and len(verdadeiras) > 0:
				
				for moeda in resultado[0]+resultado[1]:
					if moeda not in verdadeiras:
						falsas.add(moeda)

	return falsas.difference(verdadeiras)


input_file = sys.argv[1]

verdadeiras = set()
falsas = set()

medicoes = parse(input_file)

resultado = encontra_falsa(verdadeiras, falsas, medicoes)

print resultado
