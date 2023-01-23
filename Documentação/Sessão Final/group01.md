---
# Template para apresentação dos projetos desenvolvidos em 41686 - Projeto em Engenharia de Automação Industrial
# O template tem uma primeira parte com dados sobre o projeto. Após a linha com três traços
# ---
# começa o texto da página web do projeto.
# Não apagar a linha acima com três traços!

# Estes são os campos a adaptar para cada um dos grupos
title:      "Grupo 01 - Moving Pets"
group:      Grupo 01
projname:   Moving Pets
resumo: >- # ">-" serve para definir este campo com várias linhas até ao próximo campo (neste caso "company:")
        Quando um animal é sujeito a uma intervenção cirúrgica e há a necessidade de ficar hospitalizado, torna-se imperativo que, por parte da equipa veterinária, suceda um acompanhamento do estado de saúde do mesmo. Neste sentido, o projeto Moving Pets vem solucionar este problema, através do desenvolvimento de uma coleira capaz de medir o ritmo cardíaco, os níveis de oxigénio, a temperatura e, além disso, detetar o movimento do animal, dados que podem ser visualizados na aplicação móvel desenvolvida.

company:    Pet Universal
companyURL: https://petuniversal.com/pt-pt/


# Orientadores do projeto.
# Esta estrutura é uma lista em YAML, com o nome, email e organização (departamento da Universidade, empresa, ...) de cada orientador.
supervisors:
  - name: Osvaldo Pacheco
    email: orp@ua.pt
    organization: DETI
    organizationURL: http://www.ua.pt/DETI

  - name:  Luís Pinto
    email: luis.pinto@petuniversal.com
    organization: Pet Universal
    organizationURL: https://petuniversal.com/pt-pt/


# Team members
# Coordinator comes first
team:
- name: Bruna Pires
  email: bruna.ramos.pires@ua.pt
  role: coordinator

- name: André Santos 
  email: andre.ssantos@ua.pt
  role: developer

- name: Daniel Almeida 
  email: danielba@ua.pt
  role: developer

- name: Gonçalo Martins  
  email: goncalom23@ua.pt 
  role: developer

- name: João Pedrosa  
  email: joaofpedrosa@ua.pt
  role: developer

# Multimedia...
# Indicar nome dos ficheiros com o video do projeto e a imagem reoresentativa do projeto.
videoFilename:  Vídeo_Moving_Pets.mp4
thumbnailImage: Moving_Pets.jpg
# Não devem alterar as duas linhas seguintes (até à linha com "---")
layout: page
categories: pind
---

<!-- Info sobre o projeto -->
<!-- Não devem apagar a linha com o "include projinfo.md" -->
{% include projinfo.md %}

<!-- A partir deste ponto, e até ao final, está a descrição do vosso projeto -->

Aqui deve ir o texto completo do Projeto. Não deve repetir o que está no resumo escrito em cima.

# Desafio

O projeto Moving Pets tem como finalidade monitorizar o nível de atividade dos animais internados em box hospitalar.
Tendo esse objetivo em mente, as especificações inicias do presente projeto, centravam-se na necessidade de desenvolver uma coleira apta a medir os sinais vitais de um animal, bem como o seu nível de movimento.

# Resultados

Na sua versão final, o presente projeto é constituído por uma coleira standart, por um concentrador e por uma aplicação móvel para tablet.
A coleira acima referida foi desenvolvida com o propósito de medir o ritmo cardíaco, os níveis de oxigénio, a temperatura e, além do elencado, detetar os movimentos do animal. 
No que respeita ao concentrador, está previsto que se encontre ligado à rede WiFi da clínica veterinária e envie os dados recolhidos pelos sensores para uma base de dados, mais concretamente, para a Firebase. 
Em relação ao desenvolvimento da aplicação móvel para tablet, a mesma apresenta as seguintes páginas, a saber: página de login, escolha por parte do utilizador do concentrador sobre o qual pretende obter informações, indicação do nome do animal associado à coleira especificada e, por último, apresentação dos dados recolhidos pelos sensores em tempo real.


