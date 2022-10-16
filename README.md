# Text-processing-utility
Πρόγραμμα το οποίο εκτελεί επεξεργασία κειμένου με σκοπό την υλοποίηση των δοθέντων απαιτήσεων (παρακάτω).
Υλοποιήθηκε στο πλαίσιο εργασίας για το μάθημα "Βασικές Αρχές Προγραμματισμού".


## Περιγραφή προβλήματος.
Να γίνει πρόγραμμα το οποίο θα διαβάζει κείμενα από το χρήστη και θα τα αναλύει σε
λέξεις, προτάσεις και παραγράφους.
* Μία λέξη αποτελείται από 1 ή περισσότερα συνεχόμενα λατινικά γράμματα
(πεζά η/και κεφαλαία)
* Μία πρόταση αποτελείται από 1 ή περισσότερες λέξεις (που χωρίζονται με κενά
ή άλλους χαρακτήρες) που τελειώνουν με . ή ! ή ? ή ;
* Μία παράγραφος αποτελείται από 1 ή περισσότερες προτάσεις που
τελειώνουν με ένα χαρακτήρα αλλαγής γραμμής.
<br>

## Απαιτήσεις.
Το πρόγραμμα θα ζητά συνεχώς εντολές από το χρήστη μέχρι να δεχτεί την εντολή qt
η οποία τερματίζει το πρόγραμμα.
Οι εντολές που μπορεί να δεχτεί είναι:
* “ap:” Μετά από αυτή την εντολή το πρόγραμμα θα πρέπει να διαβάζει μια
παράγραφο (με μέγιστο μήκος 10000 χαρακτήρες) να την αναλύει σε
προτάσεις και λέξεις και να την αποθηκεύει σε κατάλληλες δομές στη μνήμη.
* “fw:” Μετά από αυτή την εντολή το πρόγραμμα θα πρέπει να διαβάζει μια
συμβολοσειρά (με μέγιστο μήκος 10000 χαρακτήρες) και να εμφανίζει τις λέξεις
που περιέχουν τη συγκεκριμένη συμβολοσειρά μέσα τους. Σημείωση: Το
πρόγραμμα θα πρέπει να εμφανίζει μόνο μία φορά κάθε λέξη (ακόμη και αν
αυτή επαναλαμβάνεται στο κείμενο).
* “fs:” Μετά από αυτή την εντολή το πρόγραμμα θα πρέπει να διαβάζει μια
συμβολοσειρά (με μέγιστο μήκος 10000 χαρακτήρες) και να εμφανίζει τις
προτάσεις που περιέχουν τη συγκεκριμένη συμβολοσειρά μέσα τους.
Σημείωση: Στην εμφάνιση των προτάσεων το πρόγραμμα θα πρέπει να
εμφανίζει τις λέξεις στη σωστή σειρά (χωρισμένες με ακριβώς ένα κενό) και
μετά ένα χαρακτήρα αλλαγής γραμμής. Οι υπόλοιποι χαρακτήρες που πιθανόν
να έδωσε ο χρήστης δεν θα εμφανίζονται. 
* “fp:” Μετά από αυτή την εντολή το πρόγραμμα θα πρέπει να διαβάζει μια
συμβολοσειρά (με μέγιστο μήκος 10000 χαρακτήρες) και να εμφανίζει τις
παραγράφους που περιέχουν τη συγκεκριμένη συμβολοσειρά μέσα τους.
Σημείωση: Στην εμφάνιση των παραγράφων το πρόγραμμα θα πρέπει να
εμφανίζει όλες τις προτάσεις της συγκεκριμένης παραγράφου σύμφωνα με τα
προηγούμενα. 
* “owf” Το πρόγραμμα θα πρέπει να εμφανίζει όλες τις λέξεις του κειμένου (κάθε
λέξη θα εμφανίζεται μόνο μία φορά) ταξινομημένες σε φθίνουσα σειρά με βάση
τον αριθμό εμφάνισης της κάθε λέξης στο κείμενο. Σε περίπτωση που 2 λέξεις
έχουν την ίδια συχνότητα εμφάνισης να ταξινομούνται με αύξουσα
λεξικογραφική σειρά (πρώτα τα κεφαλαία μετά τα πεζά). Κάθε λέξη θα πρέπει
να εμφανίζεται μαζί με τον αριθμός εμφάνισης της μέσα σε [] (π.χ. the [3],
εφόσον η λέξη the υπήρχε 3 φορές στο κείμενο)
* “owl” Το πρόγραμμα θα πρέπει να εμφανίζει όλες τις λέξεις του κειμένου (κάθε
λέξη θα εμφανίζεται μόνο μία φορά) ταξινομημένες σε αύξουσα σειρά με βάση
τον μήκος της κάθε λέξης. Σε περίπτωση που 2 λέξεις έχουν τo ίδιο μήκος να
ταξινομούνται με αύξουσα λεξικογραφική σειρά (πρώτα τα κεφαλαία μετά τα
πεζά). Κάθε λέξη θα πρέπει να εμφανίζεται μαζί με το μήκος της μέσα σε [] (π.χ.
Graham [6], καθώς η λέξη έχει μήκος 6 γράμματα)
* “qt” Το πρόγραμμα θα πρέπει να τερματίζει τη λειτουργία του.
