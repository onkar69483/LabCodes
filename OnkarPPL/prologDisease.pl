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
