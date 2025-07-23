function sortPeople(names: string[], heights: number[]): string[] {
  // we need to create 
  const peoples=names.map((names,idx)=>({names,heights:heights[idx]}));
  peoples.sort((a,b)=>b.heights-a.heights);
  return peoples.map((p)=>p.names);
};