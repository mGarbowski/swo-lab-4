
# System sprzedaży WhiteBear Inn

Witaj w WhiteBear, małym pensjonacie gdzieś w Polsce. Kupujemy i sprzedajemy najlepsze przedmioty na świecie. Niestety, nasze produkty stale tracą na jakości, gdy zbliżają się do daty sprzedaży. Zakupiliśmy system komputerowy, który aktualizuje nasz inwentarz. Niestety, system ten został opracowany wiele lat temu i wymaga aktualizacji.

# Specyfikacja systemu

W sklepie znajdują się 4 rodzaje produktów:

- kamizelka dodająca plus 7 punktów mocy,
- dojrzewający ser,
- bilety na koncert,
- zbroja Legolas, Hand of Gollum.

Każdy produkt ma zdefiniowaną:

- liczbę dni, w ciągu których ma być sprzedany, liczoną od daty sprowadzenia towaru do sklepu;
- wartość, która może się zmieniać w zależności od tego, jak długo produkt jest w sklepie.

Na koniec każdego dnia nasz system zmniejsza obie wartości dla każdego przedmiotu.

Format specyfikacji zawiera indeks dnia oraz (w kolejnych wierszach) atrybuty produktów znajdujących się w sklepie.

- Kolumna 1 – zawiera nazwę przedmiotu.
- Kolumna 2 – określa liczbę dni, jakie mamy na sprzedaż przedmiotu.
- Kolumna 3 – określa, jak wartościowy jest dany przedmiot.

Przykład:

```text
Day is 0
+7 Yellow Vest, 9, 19
Cheese Brie, 9, 21
Tickets to a concert, 9, 22
Legolas, Hand of Gollum, 10, 20
```

Ze specyfikacji wynika, że np. produkt „Cheese Brie” w dniu 0 powinien być sprzedany w ciągu 9 dni i jego wartość wynosi 21.

Inne wymagania:

- Po upływie daty sprzedaży jakości przedmiotu spada dwukrotnie szybciej.
- Jakość przedmiotu nigdy nie jest ujemna i nigdy nie przekracza 50.
- "Cheese Brie" zwiększa swoją jakość im starszy się staje.
- "Legolas, Hand of Gollum", będąc przedmiotem legendarnym, nigdy nie musi być sprzedawany ani nie traci na jakości.
- "Tickets to a concert", podobnie jak "Cheese Brie", zwiększają swoją jakość, gdy zbliża się ich termin przydatności: jakość wzrasta o 2, gdy pozostaje 10 dni lub mniej, i o 3, gdy pozostaje 5 dni lub mniej, ale spada do 0 po koncercie.

# Planowana rozbudowa systemu

W związku z dynamicznym rozwojem naszego pensjonatu zdecydowaliśmy się wprowadzić do oferty nowy rodzaj produktów: "Conjured" ("Zaklęte"), które tracą na jakości dwa razy szybciej niż normalne przedmioty.
