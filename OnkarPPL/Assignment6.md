# Assignment 6

## Title: Write a Prolog program that captures Medical diagnostic system.

```prolog
symptom(sachin,sneezing).
symptom(sachin,fever). 
symptom(sachin,headache). 
symptom(sachin,sore_throat).
symptom(mihir,rash).
symptom(mihir,flu). 
symptom(mihir,fever).
symptom(mihir,bodyache). 
symptom(onkar,chills). 
symptom(onkar,fever).
symptom(onkar,headache).
symptom(onkar,bodyache).
symptom(parimal,fever).
symptom(parimal,rash).
symptom(parimal,headache).
symptom(parimal,cough).
symptom(parimal,loss_of_taste).

disease(Patient,corona):-
symptom(Patient,fever),symptom(Patient,cough),symptom(Patient,loss_of_taste),!. 

disease(Patient,common_cold):-
symptom(Patient,headache),symptom(Patient,sneezing),symptom(Patient,sore_throat),!.

disease(Patient,flu):-
symptom(Patient,chills),symptom(Patient,fever),symptom(Patient,headache),!.

disease(Patient,hypertension):-
symptom(Patient,high_BP);symptom(Patient,headache),!.
```
## Input and Output

![image](https://github.com/onkar69483/LabCodes/assets/61963755/552a21f9-860e-45e3-ac95-e784c26a3231)
