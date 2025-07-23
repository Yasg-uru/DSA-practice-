function numUniqueEmails(emails: string[]): number {
    //story points 
    // 1 . remove the part after + and remove all the dots 
    // 2. store all the clean emails into the set
    // 3. return the size of the set 
    const st:Set<string>= new Set();
    for(const email of emails){
        const [local , domain]= email.split('@');
        let cleanedLocal :string = "";
        for(let i:number =0 ;i<local.length;i++){
            if(local[i]=='.' ){
                continue ;
            }
            if(local[i]==='+') break;
            cleanedLocal+=local[i];
        }
        const cleanedEmail = `${cleanedLocal}@${domain}`
        st.add(cleanedEmail);
    }
    return st.size;
    
};