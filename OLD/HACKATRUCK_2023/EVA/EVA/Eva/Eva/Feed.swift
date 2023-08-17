//
//  Feed.swift
//  Eva
//
//  Created by Student05 on 12/06/23.
//

import SwiftUI

struct Feed: View {
    
    @StateObject private var feedViewModel = FeedViewModel()
    
    @StateObject private var noticiasViewModel = NoticiasViewModel()
    
    @State private var fav_alert_state : Bool = false
    
    var body: some View {
        ZStack{
            
            Color(.white)
            
            LinearGradient(
                colors: [.white, Color("lightPurple")],
                startPoint: .top,
                endPoint: .bottom)
            
            VStack{
                HStack{
                    AsyncImage(url: URL(string: "https://cdn-icons-png.flaticon.com/512/143/143567.png")){
                        image in
                        image
                            .resizable()
                            .aspectRatio(contentMode: .fill)
                    } placeholder: {
                        Color("lightPurple")
                    }.frame(width: 30, height: 30)
                    
                    Text("Seu Feed").font(.title).foregroundColor(Color("Purple")).fontWeight(.bold)
                    
                    Spacer()
                    
                    Button("Recarregar"){
                        feedViewModel.fetch(tema: Tema.tema!, portugues: Tema.portugues!)
                    }
                }.padding(10)
                
                Text("\(feedViewModel.feeds.count) resultados em \(Tema.portugues! ? "português": "inglês").").font(.caption)
                
                Divider()
                
                ScrollView{
                    
                    ForEach(feedViewModel.feeds, id: \.self.title){ feed in
                        
                        VStack(alignment: .leading){
                            
                            HStack(alignment: .top){
                                Text(feed.title!).font(.subheadline).fontWeight(.bold).padding(4)
                                Spacer()
                                Button{
                                    noticiasViewModel.post(titulo: feed.title!, data: feed.publishedAt!, descricao: feed.description!, url: feed.url!)
                                    fav_alert_state = true
                                }  label :{
                                    Image(systemName: "heart")
                                }.alert("Notícia adicionada às favoritas!", isPresented: $fav_alert_state) {
                                    Button("OK", role: .cancel) {
                                        
                                    }
                                }
                                
                            }
                            
                            Text(feed.description!).font(.caption).padding(4)
                            
                            HStack{
                                Text(feed.publishedAt!.prefix(10))
                                    .font(.caption)
                                    .foregroundColor(Color("Purple")).fontWeight(.bold)
                                
                                Spacer()
                                
                                //if (feed.url! as AnyObject) is NSNull {
                                Link("Visitar", destination: URL(string: "\(feed.url! )") ?? URL(string: "http://teste.com")!)
                               // }
                            }
                            
                            
                        }.padding(20).background(Color.white)
                                .cornerRadius(20)
                                .shadow(color: Color.black.opacity(0.2), radius: 5, x: 0, y: 2)

                        
                    }
                    
                    Spacer()
                }
                
            }.padding(10).onAppear(){
                feedViewModel.fetch(tema: Tema.tema!, portugues: Tema.portugues!)
            }
        }
        
    }}

struct Feed_Previews: PreviewProvider {
    static var previews: some View {
        Feed()
    }
}
