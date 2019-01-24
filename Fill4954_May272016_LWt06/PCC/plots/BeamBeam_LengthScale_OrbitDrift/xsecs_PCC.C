void xsecs_PCC()
{
//=========Macro generated from canvas: can/
//=========  (Mon Nov 20 16:38:52 2017) by ROOT version5.99/05
   TCanvas *can = new TCanvas("can", "",0,0,800,600);
   can->SetHighLightColor(2);
   can->Range(-0.08550005,8.277006,6.0855,8.586884);
   can->SetFillColor(0);
   can->SetBorderMode(0);
   can->SetBorderSize(2);
   can->SetFrameBorderMode(0);
   can->SetFrameBorderMode(0);
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("");
   multigraph->SetTitle(";Scan Pair;#sigma_{Vis} (Barn)");
   
   Double_t Graph_fx1001[5] = {
   0.8,
   1.8,
   2.8,
   3.8,
   4.8};
   Double_t Graph_fy1001[5] = {
   8.422313,
   8.415748,
   8.40613,
   8.397323,
   8.399423};
   Double_t Graph_fex1001[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1001[5] = {
   0.05526955,
   0.03681576,
   0.08686774,
   0.03746054,
   0.03598711};
   TGraphErrors *gre = new TGraphErrors(5,Graph_fx1001,Graph_fy1001,Graph_fex1001,Graph_fey1001);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","Graph",100,0.4,5.2);
   Graph_Graph1001->SetMinimum(8.301889);
   Graph_Graph1001->SetMaximum(8.510371);
   Graph_Graph1001->SetDirectory(0);
   Graph_Graph1001->SetStats(0);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#000099");
   Graph_Graph1001->SetLineColor(ci);
   Graph_Graph1001->GetXaxis()->SetLabelFont(42);
   Graph_Graph1001->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1001->GetXaxis()->SetTitleFont(42);
   Graph_Graph1001->GetYaxis()->SetLabelFont(42);
   Graph_Graph1001->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1001->GetYaxis()->SetTitleFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1001->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1001);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1002[5] = {
   0.9,
   1.9,
   2.9,
   3.9,
   4.9};
   Double_t Graph_fy1002[5] = {
   8.452386,
   8.460438,
   8.414644,
   8.401689,
   8.460704};
   Double_t Graph_fex1002[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1002[5] = {
   0.03458924,
   0.03429571,
   0.03258214,
   0.04230822,
   0.02478643};
   gre = new TGraphErrors(5,Graph_fx1002,Graph_fy1002,Graph_fex1002,Graph_fey1002);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#cc0000");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#cc0000");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1002 = new TH1F("Graph_Graph1002","Graph",100,0.5,5.3);
   Graph_Graph1002->SetMinimum(8.345846);
   Graph_Graph1002->SetMaximum(8.508269);
   Graph_Graph1002->SetDirectory(0);
   Graph_Graph1002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1002->SetLineColor(ci);
   Graph_Graph1002->GetXaxis()->SetLabelFont(42);
   Graph_Graph1002->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1002->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1002->GetXaxis()->SetTitleFont(42);
   Graph_Graph1002->GetYaxis()->SetLabelFont(42);
   Graph_Graph1002->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1002->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1002->GetYaxis()->SetTitleFont(42);
   Graph_Graph1002->GetZaxis()->SetLabelFont(42);
   Graph_Graph1002->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1002->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1002->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1002);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1003[5] = {
   1,
   2,
   3,
   4,
   5};
   Double_t Graph_fy1003[5] = {
   8.508129,
   8.465743,
   8.4548,
   8.423904,
   8.483879};
   Double_t Graph_fex1003[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1003[5] = {
   0.03649904,
   0.03485387,
   0.02429921,
   0.02386068,
   0.03452392};
   gre = new TGraphErrors(5,Graph_fx1003,Graph_fy1003,Graph_fex1003,Graph_fey1003);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#00cc00");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#00cc00");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1003 = new TH1F("Graph_Graph1003","Graph",100,0.6,5.4);
   Graph_Graph1003->SetMinimum(8.385584);
   Graph_Graph1003->SetMaximum(8.559087);
   Graph_Graph1003->SetDirectory(0);
   Graph_Graph1003->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1003->SetLineColor(ci);
   Graph_Graph1003->GetXaxis()->SetLabelFont(42);
   Graph_Graph1003->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1003->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1003->GetXaxis()->SetTitleFont(42);
   Graph_Graph1003->GetYaxis()->SetLabelFont(42);
   Graph_Graph1003->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1003->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1003->GetYaxis()->SetTitleFont(42);
   Graph_Graph1003->GetZaxis()->SetLabelFont(42);
   Graph_Graph1003->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1003->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1003->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1003);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1004[5] = {
   1.1,
   2.1,
   3.1,
   4.1,
   5.1};
   Double_t Graph_fy1004[5] = {
   8.391237,
   8.421935,
   8.389764,
   8.395038,
   8.440971};
   Double_t Graph_fex1004[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1004[5] = {
   0.03512927,
   0.03702282,
   0.02289797,
   0.02,
   0.02401025};
   gre = new TGraphErrors(5,Graph_fx1004,Graph_fy1004,Graph_fex1004,Graph_fey1004);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#0000cc");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#0000cc");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1004 = new TH1F("Graph_Graph1004","Graph",100,0.7,5.5);
   Graph_Graph1004->SetMinimum(8.34522);
   Graph_Graph1004->SetMaximum(8.475869);
   Graph_Graph1004->SetDirectory(0);
   Graph_Graph1004->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1004->SetLineColor(ci);
   Graph_Graph1004->GetXaxis()->SetLabelFont(42);
   Graph_Graph1004->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1004->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1004->GetXaxis()->SetTitleFont(42);
   Graph_Graph1004->GetYaxis()->SetLabelFont(42);
   Graph_Graph1004->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1004->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1004->GetYaxis()->SetTitleFont(42);
   Graph_Graph1004->GetZaxis()->SetLabelFont(42);
   Graph_Graph1004->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1004->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1004->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1004);
   
   multigraph->Add(gre,"");
   
   Double_t Graph_fx1005[5] = {
   1.2,
   2.2,
   3.2,
   4.2,
   5.2};
   Double_t Graph_fy1005[5] = {
   8.457043,
   8.446232,
   8.442827,
   8.379679,
   8.419806};
   Double_t Graph_fex1005[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t Graph_fey1005[5] = {
   0.02831133,
   0.02973032,
   0.02108313,
   0.02127185,
   0.02};
   gre = new TGraphErrors(5,Graph_fx1005,Graph_fy1005,Graph_fex1005,Graph_fey1005);
   gre->SetName("Graph");
   gre->SetTitle("Graph");
   gre->SetFillColor(1);

   ci = TColor::GetColor("#cc00cc");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#cc00cc");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1005 = new TH1F("Graph_Graph1005","Graph",100,0.8,5.6);
   Graph_Graph1005->SetMinimum(8.345713);
   Graph_Graph1005->SetMaximum(8.498049);
   Graph_Graph1005->SetDirectory(0);
   Graph_Graph1005->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1005->SetLineColor(ci);
   Graph_Graph1005->GetXaxis()->SetLabelFont(42);
   Graph_Graph1005->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1005->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1005->GetXaxis()->SetTitleFont(42);
   Graph_Graph1005->GetYaxis()->SetLabelFont(42);
   Graph_Graph1005->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1005->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1005->GetYaxis()->SetTitleFont(42);
   Graph_Graph1005->GetZaxis()->SetLabelFont(42);
   Graph_Graph1005->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1005->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1005->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1005);
   
   multigraph->Add(gre,"");
   multigraph->Draw("AP");
   multigraph->GetXaxis()->SetTitle("Scan Pair");
   multigraph->GetXaxis()->SetRange(0,101);
   multigraph->GetXaxis()->SetNdivisions(6);
   multigraph->GetXaxis()->SetLabelFont(42);
   multigraph->GetXaxis()->SetLabelSize(0.035);
   multigraph->GetXaxis()->SetTitleSize(0.035);
   multigraph->GetXaxis()->SetTitleFont(42);
   multigraph->GetYaxis()->SetTitle("#sigma_{Vis} (Barn)");
   multigraph->GetYaxis()->SetLabelFont(42);
   multigraph->GetYaxis()->SetLabelSize(0.035);
   multigraph->GetYaxis()->SetTitleSize(0.035);
   multigraph->GetYaxis()->SetTitleFont(42);
   TLatex *   tex = new TLatex(0.93,0.88,"2016  (13 TeV)");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.15,0.88,"CMS #bf{#scale[0.75]{#it{Preliminary}}}");
tex->SetNDC();
   tex->SetLineWidth(2);
   tex->Draw();
   
   TLegend *leg = new TLegend(0.7,0.15,0.9,0.43,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph","BX = 41","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","BX = 281","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#cc0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","BX = 872","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#00cc00");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","BX = 1783","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#0000cc");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph","BX = 2063","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#cc00cc");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   can->Modified();
   can->cd();
   can->SetSelected(can);
}
