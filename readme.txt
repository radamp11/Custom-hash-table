Autorzy:
	Rafał Surdej nr albumu 300271
	Adam Stec nr albumu 300261

Specyfikacja problemu:
	Problem polega na zaimplementowaniu tablicy mieszającej, w której kluczami są losowo generowane napisy, a watościami struktury zawierające te właśnie napisy. W tablicy dostępne są metody dodawania oraz usuwania. W przypadku kolizji, to jest wystąpienia po raz drugi lub kolejny klucza z tym samym kodem zwróconym przez funkcję mieszającą, przeszukiwane są kolejne komórki tablicy (w stronę rosnących indeksów), do momentu znalezienia wolnej komórki. W przypadku przepełnienia tablicy, kolejne elementy nie są do niej dodawane.
	
Uruchomienie programu:
	Program podczas uruchomienia przyjmuje 2 parametry. Pierwszym z nich jest wielkość tablicy mieszającej (ilość komórek), a drugim jedna z trzech funkcji mieszających.
	
Dane wejściowe oraz wyniki:
	Danymi wejściowymi są stringi pobierane ze standardowego wejścia lub z pliku. W drugim przypadku, użytkownik podaje w programie nazwę pliku, z którego chce czytać. Może też ją zmienić w dowolnym momencie z poziomu interaktywnegu menu programu. Wyniki są prezentowane na standardowym wejściu. Po wykonaniu określonej liczby operacji dodawania lub usuwania, wyświetlany jest czasm, w jakim te operacje zostały wykonane. Użytkownik ma też możliwość podejrzeć aktualną zawartośc tablicy z poziomu menu.
	
Krótki opis rozwiązania:
	 Program składa się z trzech podprogramów. Pierwszy z nich to główny program z tablicą mieszającą. Posiada interaktywne menu, z poziomu którego użytkownik może przetestować wszystkie funkcjonalności programu. W samej tablicy mieszającej zaimplementowane są trzy różne funkcje haszujące. To, która z nich używana jest w tablicy, zależy od parametrów uruchomienia programu. Dwie z nich liczą (w różny sposób, o tym w dokumentacji) indeks w tablicy na podstawie otrzymanego napisu, zaś trzecia zawsze zwraca ten sam indeks. Można dzięki temu zauważyć różnice w działaniu już przy niewielkich rozmiarach danych wejściowych. Generator, jak nazwa wskazuje, generuje losowe napisy na podstawie tekstu pobranego z pliku tekstowego. Na początku zlicza on ile razy każda litera występuje po danej literze, a później na tej podstawie tworzy tablice prawdopodobieństw wystąpienia tych liter w generowanych słowach. Znaki, które nie są literami, traktowane są jako znaki specjalne kończące wyraz. Na podstawie tablicy prawdopodobieństw program generuje określoną liczbę słów (jest to parametr uruchomienia programu) na standardowe wyjście. Przekierowując to wyjście można łatwo zapisać dane do pliku. Ostatnim już "programem" jest skrypt języka Python, który służy do oczyszczania pierwotnego tekstu ze specjalnych znaków oraz zamiany polskich liter na ich odpowiedniki w kodzie ASCII.
	
Dekompozycja programu:
	HashTable.h oraz HashTable.cpp - deklaracja oraz definicja klasy reprezentującej tablicę mieszającą
	Main.cpp - główny program używający powyższej tablicy oraz menu dla interakcji z użytkownikiem
	Generator.h - zawiera pliki nagłówkowe oraz definicje struktury używanej w generatorze
	Generator.cpp - plik źródłowy zawierający kod generatora, nie jest to jednak klasa, a osobny program zawierający własną funkcje main()
	text_cleaner.py - skrypt do oczyszczania tekstu wejściowego
	generate.sh - linuxowy skrypt pomocniczy, służy do oczyszczenia oraz wygenerowania określonej liczby słów do pliku

Dodatkowe informacje:
	O ile główny program nie jest związany z żadnym konkretnym plikiem, o tyle programy pomocnicze już tak. Skrypt oczyszczający czyta tekst z pliku "text_file.txt", oraz zapisuje go do pliku "text.txt". Podobnie generator czyta z pliku "text.txt". W pomocniczym skrypcie generate.sh mamy stałą reprezentującą ilość słów do wygenerowania (domyślnie 1000000) oraz przekierowanie wyjścia z generatora do pliku "generated.txt". Aby uruchomić skrypt w systemie linux, trzeba nadać mu uprawnienia do uruchamiania poprzez komendę "chmod +x generate.sh".
	Zarówno w tablicy, jak i w programie użytkownika sprawdzane są najczęstsze sytuacje wyjątkowe (czy rozmiar tablicy nie jest ujemny, czy udało się otworzyć plik wejściowy), jednak nie wszystkie. Dlatego też staraliśmy się stworzyć proste menu, które dokładnie pokazuje użytkownikowi jakie ma w danym momencie możliwości wyboru.
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
